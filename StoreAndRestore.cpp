//
// Created by Jarvis on 5/8/2019.
//


#include "StoreAndRestore.h"
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QFile>

void makeJson(QJsonDocument &jsdoc,const BBVB &b){
    QJsonObject all;

    //-----------------------------------------
    QJsonObject host;
    host.insert(QString("firstName"),QJsonValue(b.getHost().getFirstName()));
    host.insert(QString("lastName"),QJsonValue(b.getHost().getLastName()));
    host.insert(QString("gender"),QJsonValue(b.getHost().getGender()));
    host.insert(QString("nationalCode"),QJsonValue(b.getHost().getNationalCode()));
    all.insert(QString("Host"),QJsonValue(host));

    //----------------------------------
    all.insert(QString("username"),QJsonValue(b.getUsername()));
    all.insert(QString("password"),QJsonValue(b.getPassword()));
    all.insert(QString("firstTime"),QJsonValue(b.isFirstTime()));

    //-----------------------------------
    QJsonArray teamArray;
    for(int i=0;i<b.getTeams().size();i++){
        QJsonObject team;
        team.insert(QString("ID"),QJsonValue(b.getTeams()[i].getID()));
        team.insert(QString("teamName"),QJsonValue(b.getTeams()[i].getTeamName()));
        team.insert(QString("username"),QJsonValue(b.getTeams()[i].getUsername()));
        team.insert(QString("password"),QJsonValue(b.getTeams()[i].getPassword()));
        team.insert(QString("score"),QJsonValue(b.getTeams()[i].getScore()));

        //--------------------------
        QJsonArray persons;
        for(int j=0;b.getTeams()[i].getMembers().size();i++){
            QJsonObject person;
            person.insert(QString("firstName"),QJsonValue(b.getTeams()[i].getMembers()[j].getFirstName()));
            person.insert(QString("lastName"),QJsonValue(b.getTeams()[i].getMembers()[j].getLastName()));
            person.insert(QString("gender"),QJsonValue(b.getTeams()[i].getMembers()[j].getGender()));
            person.insert(QString("nationalCode"),QJsonValue(b.getTeams()[i].getMembers()[j].getNationalCode()));
            persons.push_back(QJsonValue(person));
        }
        team.insert(QString("members"),QJsonValue(persons));

        teamArray.push_back(QJsonValue(team));
    }
    all.insert(QString("teams"),QJsonValue(teamArray));


    //-----------------------------------------------
    QJsonArray tours;
    for(int i=0;i<b.getTours().size();i++){
        QJsonObject tour;
        tour.insert(QString("ID"),QJsonValue(b.getTours()[i].getTourId()));

        //-----------------------------------------
        MyDate start=b.getTours()[i].getTourStartDate();
        tour.insert(QString("startYear"),QJsonValue(start.getYear()));
        tour.insert(QString("starMonth"),QJsonValue(start.getMonth()));
        tour.insert(QString("startDay"),QJsonValue(start.getDay()));

        MyDate end=b.getTours()[i].getTourEndDate();
        tour.insert(QString("endYear"),QJsonValue(end.getYear()));
        tour.insert(QString("endMonth"),QJsonValue(end.getMonth()));
        tour.insert(QString("endDay"),QJsonValue(end.getDay()));


        //-----------------------------------------
        QJsonArray matches;
        for(int j=0;j<b.getTours()[i].getTourMatches().size();j++){
            Match<VBResult> m=b.getTours()[i].getTourMatches()[j];
            QJsonObject match;
            match.insert(QString("ID"),QJsonValue(m.getId()));

            MyDate hold=m.getHoldingDate();
            match.insert(QString("holdingDateYear"),QJsonValue(hold.getYear()));
            match.insert(QString("holdingDateMonth"),QJsonValue(hold.getMonth()));
            match.insert(QString("holdingDateDay"),QJsonValue(hold.getDay()));

            MyTime start=m.getStartTime();
            match.insert(QString("matchStartHour"),QJsonValue(start.getHour()));
            match.insert(QString("matchStartMin"),QJsonValue(start.getMin()));

            MyTime end=m.getEndTime();
            match.insert(QString("matchEndHour"),QJsonValue(end.getHour()));
            match.insert(QString("matchEndMin"),QJsonValue(end.getMin()));



            QJsonObject first;
            first.insert(QString("ID"),QJsonValue(m.getFirstTeamId()));
            VBResult re1=m.getFirstTeamResult();
            QJsonArray sets1;
            sets1.push_back(QJsonValue(re1.set1));
            sets1.push_back(QJsonValue(re1.set2));
            sets1.push_back(QJsonValue(re1.set3));
            sets1.push_back(QJsonValue(re1.set4));
            sets1.push_back(QJsonValue(re1.set5));
            first.insert(QString("result"),QJsonValue(sets1));
            match.insert(QString("firstTeam"),QJsonValue(first));

            QJsonObject second;
            second.insert(QString("ID"),QJsonValue(m.getSecondTeamId()));
            VBResult re2=m.getSecondTeamResult();
            QJsonArray sets2;
            sets2.push_back(QJsonValue(re2.set1));
            sets2.push_back(QJsonValue(re2.set2));
            sets2.push_back(QJsonValue(re2.set3));
            sets2.push_back(QJsonValue(re2.set4));
            sets2.push_back(QJsonValue(re2.set5));
            second.insert(QString("result"),QJsonValue(sets2));
            match.insert(QString("secondTeam"),QJsonValue(second));


            matches.push_back(QJsonValue(match));
        }
        tour.insert(QString("matches"),QJsonValue(matches));


        //------------------------------------------------
        QJsonArray ids;
        for(int j=0;j<b.getTours()[i].getTeamIDs().size();j++){
            ids.push_back(QJsonValue(b.getTours()[i].getTeamIDs()[j]));
        }
        tour.insert(QString("teamIDs"),QJsonValue(ids));


        tours.push_back(tour);
    }


    all.insert(QString("tours"),QJsonValue(tours));
    jsdoc.setObject(all);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeBBVB(QJsonDocument &jsdoc,BBVB &b){
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    QJsonObject all = jsdoc.object();

    //-----------------------------------------------------
    Person host;
    QJsonObject jhost = all[QString("Host")].toObject();
    host.setFirstName(jhost["firstName"].toString());
    host.setLasName(all["lastName"].toString());
    host.setNationalCode(all["nationalCode"].toString());
    host.setGender(all["gender"].toBool());
    b.setHost(host);

    //----------------------------------------------------
    b.setUsername(all["username"].toString());
    b.setPassword(all["password"].toString());
    b.setFirstTime(all["firstTime"].toBool());

    //-----------------------------------------------------
    QJsonArray jteams=all["teams"].toArray();
    QVector<Team> teams;
    for(int i=0;i<jteams.size();i++){
        QJsonObject jteam=jteams[i].toObject();
        Team team;
        team.setID(jteam["ID"].toInt());
        team.setUsername(jteam["username"].toString());
        team.setPassword(jteam["password"].toString());
        team.setTeamName(jteam["teamName"].toString());
        team.setScore(jteam["score"].toInt());

        QJsonArray jmembers=jteam["members"].toArray();
        for(int j=0;j<jmembers.size();j++){
            Person member;
            QJsonObject jmember=jmembers[j].toObject();
            member.setFirstName(jmember["firstName"].toString());
            member.setLasName(jmember["lastName"].toString());
            member.setNationalCode(jmember["nationalCode"].toString());
            member.setGender(jmember["gender"].toBool());

            team.addPerson(member);
        }
        teams.push_back(team);
    }
    b.setTeams(teams);


    //--------------------------------------------------------
    QJsonArray jtours=all["tours"].toArray();
    QVector<Tournament<VBResult>> tours;
    for(int i=0;i<jtours.size();i++){
        QJsonObject jtour=jtours[i].toObject();
        Tournament<VBResult> tour;
        tour.setID(jtour["ID"].toInt());

        MyDate start;
        start.setYear(jtour["startYear"].toInt());
        start.setMonth(jtour["startMonth"].toInt());
        start.setDay(jtour["startDay"].toInt());
        tour.setTourStartDate(start);

        MyDate end;
        end.setYear(jtour["endYear"].toInt());
        end.setMonth(jtour["endMonth"].toInt());
        end.setDay(jtour["endDay"].toInt());
        tour.setTourStartDate(end);

        QJsonArray jmatches=jtour["matches"].toArray();
        QVector<Match<VBResult>> matches;
        for(int j=0;j<jmatches.size();j++){
            QJsonObject jmatch=jmatches[i].toObject();
            Match<VBResult> match;

            match.setID(jmatch["ID"].toInt());

            MyDate hold;
            hold.setYear(jmatch["holdingDateYear"].toInt());
            hold.setMonth(jmatch["holdingDateMonth"].toInt());
            hold.setDay(jmatch["holdingDateDay"].toInt());
            match.setHoldingDate(hold);

            MyTime start;
            start.setHour(jmatch["matchStartHour"].toInt());
            start.setMin(jmatch["matchStartMin"].toInt());
            match.setStart(start);

            MyTime end;
            end.setHour(jmatch["matchEndHour"].toInt());
            end.setMin(jmatch["matchEndMin"].toInt());
            match.setEnd(end);


            QJsonObject jfirst=jmatch["firstTeam"].toObject();
            match.setFirstTeamId(jfirst["ID"].toInt());
            QJsonArray jre=jfirst["result"].toArray();
            VBResult re;
            re.set1=jre[0].toInt();
            re.set2=jre[1].toInt();
            re.set3=jre[2].toInt();
            re.set4=jre[3].toInt();
            re.set5=jre[4].toInt();
            match.setFirstTeamResult(re);

            QJsonObject jsecond=jmatch["secondTeam"].toObject();
            match.setSecondTeamId(jsecond["ID"].toInt());
            QJsonArray jre2=jsecond["result"].toArray();
            VBResult re2;
            re2.set1=jre2[0].toInt();
            re2.set2=jre2[1].toInt();
            re2.set3=jre2[2].toInt();
            re2.set4=jre2[3].toInt();
            re2.set5=jre2[4].toInt();
            match.setFirstTeamResult(re2);


            matches.push_back(match);
        }
        tour.setMatches(matches);

        QJsonArray jids=jtour["teamIDs"].toArray();
        QVector<int> ids;
        for(int j=0;j<jids.size();j++){
            ids.push_back(jids[i].toInt());
        }
        tour.setTeamIDs(ids);

        tours.push_back(tour);
    }
    b.setTours(tours);
}

void Start(BBVB &b){
    QFile json(QString("bbvb.json"));
    json.open(QFile::ReadOnly);
    QJsonDocument jsdoc=QJsonDocument().fromJson(json.readAll());
    makeBBVB(jsdoc,b);
    json.close();
}
void Update(const BBVB &b){
    QJsonDocument doc;
    makeJson(doc,b);
    QFile json(QString("bbvb.json"));
    json.open(QFile::WriteOnly);
    json.write(doc.toJson());
    json.close();
}




/*
 *
 *
 *
 *
 *
 * fuck this shit i'm out!
 *
 *
 *
 *
 */



//-----------------------------------------------------

void makeJson(QJsonDocument &jsdoc,const PingPong &b){
    QJsonObject all;

    //-----------------------------------------
    QJsonObject host;
    host.insert(QString("firstName"),QJsonValue(b.getHost().getFirstName()));
    host.insert(QString("lastName"),QJsonValue(b.getHost().getLastName()));
    host.insert(QString("gender"),QJsonValue(b.getHost().getGender()));
    host.insert(QString("nationalCode"),QJsonValue(b.getHost().getNationalCode()));
    all.insert(QString("Host"),QJsonValue(host));

    //----------------------------------
    all.insert(QString("username"),QJsonValue(b.getUsername()));
    all.insert(QString("password"),QJsonValue(b.getPassword()));
    all.insert(QString("firstTime"),QJsonValue(b.isFirstTime()));

    //-----------------------------------
    QJsonArray teamArray;
    for(int i=0;i<b.getTeams().size();i++){
        QJsonObject team;
        team.insert(QString("ID"),QJsonValue(b.getTeams()[i].getID()));
        team.insert(QString("teamName"),QJsonValue(b.getTeams()[i].getTeamName()));
        team.insert(QString("username"),QJsonValue(b.getTeams()[i].getUsername()));
        team.insert(QString("password"),QJsonValue(b.getTeams()[i].getPassword()));
        team.insert(QString("score"),QJsonValue(b.getTeams()[i].getScore()));

        //--------------------------
        QJsonArray persons;
        for(int j=0;b.getTeams()[i].getMembers().size();i++){
            QJsonObject person;
            person.insert(QString("firstName"),QJsonValue(b.getTeams()[i].getMembers()[j].getFirstName()));
            person.insert(QString("lastName"),QJsonValue(b.getTeams()[i].getMembers()[j].getLastName()));
            person.insert(QString("gender"),QJsonValue(b.getTeams()[i].getMembers()[j].getGender()));
            person.insert(QString("nationalCode"),QJsonValue(b.getTeams()[i].getMembers()[j].getNationalCode()));
            persons.push_back(QJsonValue(person));
        }
        team.insert(QString("members"),QJsonValue(persons));

        teamArray.push_back(QJsonValue(team));
    }
    all.insert(QString("teams"),QJsonValue(teamArray));


    //-----------------------------------------------
    QJsonArray tours;
    for(int i=0;i<b.getTours().size();i++){
        QJsonObject tour;
        tour.insert(QString("ID"),QJsonValue(b.getTours()[i].getTourId()));

        //-----------------------------------------
        MyDate start=b.getTours()[i].getTourStartDate();
        tour.insert(QString("startYear"),QJsonValue(start.getYear()));
        tour.insert(QString("starMonth"),QJsonValue(start.getMonth()));
        tour.insert(QString("startDay"),QJsonValue(start.getDay()));

        MyDate end=b.getTours()[i].getTourEndDate();
        tour.insert(QString("endYear"),QJsonValue(end.getYear()));
        tour.insert(QString("endMonth"),QJsonValue(end.getMonth()));
        tour.insert(QString("endDay"),QJsonValue(end.getDay()));


        //-----------------------------------------
        QJsonArray matches;
        for(int j=0;j<b.getTours()[i].getTourMatches().size();j++){
            Match<PPResult> m=b.getTours()[i].getTourMatches()[j];
            QJsonObject match;
            match.insert(QString("ID"),QJsonValue(m.getId()));

            MyDate hold=m.getHoldingDate();
            match.insert(QString("holdingDateYear"),QJsonValue(hold.getYear()));
            match.insert(QString("holdingDateMonth"),QJsonValue(hold.getMonth()));
            match.insert(QString("holdingDateDay"),QJsonValue(hold.getDay()));

            MyTime start=m.getStartTime();
            match.insert(QString("matchStartHour"),QJsonValue(start.getHour()));
            match.insert(QString("matchStartMin"),QJsonValue(start.getMin()));

            MyTime end=m.getEndTime();
            match.insert(QString("matchEndHour"),QJsonValue(end.getHour()));
            match.insert(QString("matchEndMin"),QJsonValue(end.getMin()));



            QJsonObject first;
            first.insert(QString("ID"),QJsonValue(m.getFirstTeamId()));
            PPResult re1=m.getFirstTeamResult();
            QJsonArray sets1;
            sets1.push_back(QJsonValue(re1.set1));
            sets1.push_back(QJsonValue(re1.set2));
            sets1.push_back(QJsonValue(re1.set3));
            first.insert(QString("result"),QJsonValue(sets1));
            match.insert(QString("firstTeam"),QJsonValue(first));

            QJsonObject second;
            second.insert(QString("ID"),QJsonValue(m.getSecondTeamId()));
            PPResult re2=m.getSecondTeamResult();
            QJsonArray sets2;
            sets2.push_back(QJsonValue(re2.set1));
            sets2.push_back(QJsonValue(re2.set2));
            sets2.push_back(QJsonValue(re2.set3));
            second.insert(QString("result"),QJsonValue(sets2));
            match.insert(QString("secondTeam"),QJsonValue(second));


            matches.push_back(QJsonValue(match));
        }
        tour.insert(QString("matches"),QJsonValue(matches));


        //------------------------------------------------
        QJsonArray ids;
        for(int j=0;j<b.getTours()[i].getTeamIDs().size();j++){
            ids.push_back(QJsonValue(b.getTours()[i].getTeamIDs()[j]));
        }
        tour.insert(QString("teamIDs"),QJsonValue(ids));


        tours.push_back(tour);
    }


    all.insert(QString("tours"),QJsonValue(tours));
    jsdoc.setObject(all);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makePingPong(QJsonDocument &jsdoc,PingPong &b){
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    QJsonObject all = jsdoc.object();

    //-----------------------------------------------------
    Person host;
    QJsonObject jhost = all[QString("Host")].toObject();
    host.setFirstName(jhost["firstName"].toString());
    host.setLasName(all["lastName"].toString());
    host.setNationalCode(all["nationalCode"].toString());
    host.setGender(all["gender"].toBool());
    b.setHost(host);

    //----------------------------------------------------
    b.setUsername(all["username"].toString());
    b.setPassword(all["password"].toString());
    b.setFirstTime(all["firstTime"].toBool());

    //-----------------------------------------------------
    QJsonArray jteams=all["teams"].toArray();
    QVector<Team> teams;
    for(int i=0;i<jteams.size();i++){
        QJsonObject jteam=jteams[i].toObject();
        Team team;
        team.setID(jteam["ID"].toInt());
        team.setUsername(jteam["username"].toString());
        team.setPassword(jteam["password"].toString());
        team.setTeamName(jteam["teamName"].toString());
        team.setScore(jteam["score"].toInt());

        QJsonArray jmembers=jteam["members"].toArray();
        for(int j=0;j<jmembers.size();j++){
            Person member;
            QJsonObject jmember=jmembers[j].toObject();
            member.setFirstName(jmember["firstName"].toString());
            member.setLasName(jmember["lastName"].toString());
            member.setNationalCode(jmember["nationalCode"].toString());
            member.setGender(jmember["gender"].toBool());

            team.addPerson(member);
        }
        teams.push_back(team);
    }
    b.setTeams(teams);


    //--------------------------------------------------------
    QJsonArray jtours=all["tours"].toArray();
    QVector<Tournament<PPResult>> tours;
    for(int i=0;i<jtours.size();i++){
        QJsonObject jtour=jtours[i].toObject();
        Tournament<PPResult> tour;
        tour.setID(jtour["ID"].toInt());

        MyDate start;
        start.setYear(jtour["startYear"].toInt());
        start.setMonth(jtour["startMonth"].toInt());
        start.setDay(jtour["startDay"].toInt());
        tour.setTourStartDate(start);

        MyDate end;
        end.setYear(jtour["endYear"].toInt());
        end.setMonth(jtour["endMonth"].toInt());
        end.setDay(jtour["endDay"].toInt());
        tour.setTourStartDate(end);

        QJsonArray jmatches=jtour["matches"].toArray();
        QVector<Match<PPResult>> matches;
        for(int j=0;j<jmatches.size();j++){
            QJsonObject jmatch=jmatches[i].toObject();
            Match<PPResult> match;

            match.setID(jmatch["ID"].toInt());

            MyDate hold;
            hold.setYear(jmatch["holdingDateYear"].toInt());
            hold.setMonth(jmatch["holdingDateMonth"].toInt());
            hold.setDay(jmatch["holdingDateDay"].toInt());
            match.setHoldingDate(hold);

            MyTime start;
            start.setHour(jmatch["matchStartHour"].toInt());
            start.setMin(jmatch["matchStartMin"].toInt());
            match.setStart(start);

            MyTime end;
            end.setHour(jmatch["matchEndHour"].toInt());
            end.setMin(jmatch["matchEndMin"].toInt());
            match.setEnd(end);


            QJsonObject jfirst=jmatch["firstTeam"].toObject();
            match.setFirstTeamId(jfirst["ID"].toInt());
            QJsonArray jre=jfirst["result"].toArray();
            PPResult re;
            re.set1=jre[0].toInt();
            re.set2=jre[1].toInt();
            re.set3=jre[2].toInt();
            match.setFirstTeamResult(re);

            QJsonObject jsecond=jmatch["secondTeam"].toObject();
            match.setSecondTeamId(jsecond["ID"].toInt());
            QJsonArray jre2=jsecond["result"].toArray();
            PPResult re2;
            re2.set1=jre2[0].toInt();
            re2.set2=jre2[1].toInt();
            re2.set3=jre2[2].toInt();
            match.setFirstTeamResult(re2);


            matches.push_back(match);
        }
        tour.setMatches(matches);

        QJsonArray jids=jtour["teamIDs"].toArray();
        QVector<int> ids;
        for(int j=0;j<jids.size();j++){
            ids.push_back(jids[i].toInt());
        }
        tour.setTeamIDs(ids);

        tours.push_back(tour);
    }
    b.setTours(tours);
}


void Start(PingPong &p){
    QFile json(QString("PingPong.json"));
    json.open(QFile::ReadOnly);
    QJsonDocument jsdoc=QJsonDocument().fromJson(json.readAll());
    makePingPong(jsdoc,p);
    json.close();
}
void Update(const PingPong &p){
    QJsonDocument doc;
    makeJson(doc,p);
    QFile json(QString("PingPong.json"));
    json.open(QFile::WriteOnly);
    json.write(doc.toJson());
    json.close();
}




/*
 *
 *
 *
 *
 *
 * fuck this shit i'm out!
 *
 *
 *
 *
 */



//----------------------------------------------------------------
void makeJson(QJsonDocument &jsdoc,const Wrestling &b){
    QJsonObject all;

    //-----------------------------------------
    QJsonObject host;
    host.insert(QString("firstName"),QJsonValue(b.getHost().getFirstName()));
    host.insert(QString("lastName"),QJsonValue(b.getHost().getLastName()));
    host.insert(QString("gender"),QJsonValue(b.getHost().getGender()));
    host.insert(QString("nationalCode"),QJsonValue(b.getHost().getNationalCode()));
    all.insert(QString("Host"),QJsonValue(host));

    //----------------------------------
    all.insert(QString("username"),QJsonValue(b.getUsername()));
    all.insert(QString("password"),QJsonValue(b.getPassword()));
    all.insert(QString("firstTime"),QJsonValue(b.isFirstTime()));

    //-----------------------------------
    QJsonArray teamArray;
    for(int i=0;i<b.getTeams().size();i++){
        QJsonObject team;
        team.insert(QString("ID"),QJsonValue(b.getTeams()[i].getID()));
        team.insert(QString("teamName"),QJsonValue(b.getTeams()[i].getTeamName()));
        team.insert(QString("username"),QJsonValue(b.getTeams()[i].getUsername()));
        team.insert(QString("password"),QJsonValue(b.getTeams()[i].getPassword()));
        team.insert(QString("score"),QJsonValue(b.getTeams()[i].getScore()));

        //--------------------------
        QJsonArray persons;
        for(int j=0;b.getTeams()[i].getMembers().size();i++){
            QJsonObject person;
            person.insert(QString("firstName"),QJsonValue(b.getTeams()[i].getMembers()[j].getFirstName()));
            person.insert(QString("lastName"),QJsonValue(b.getTeams()[i].getMembers()[j].getLastName()));
            person.insert(QString("gender"),QJsonValue(b.getTeams()[i].getMembers()[j].getGender()));
            person.insert(QString("nationalCode"),QJsonValue(b.getTeams()[i].getMembers()[j].getNationalCode()));
            persons.push_back(QJsonValue(person));
        }
        team.insert(QString("members"),QJsonValue(persons));

        teamArray.push_back(QJsonValue(team));
    }
    all.insert(QString("teams"),QJsonValue(teamArray));


    //-----------------------------------------------
    QJsonArray tours;
    for(int i=0;i<b.getTours().size();i++){
        QJsonObject tour;
        tour.insert(QString("ID"),QJsonValue(b.getTours()[i].getTourId()));

        //-----------------------------------------
        MyDate start=b.getTours()[i].getTourStartDate();
        tour.insert(QString("startYear"),QJsonValue(start.getYear()));
        tour.insert(QString("starMonth"),QJsonValue(start.getMonth()));
        tour.insert(QString("startDay"),QJsonValue(start.getDay()));

        MyDate end=b.getTours()[i].getTourEndDate();
        tour.insert(QString("endYear"),QJsonValue(end.getYear()));
        tour.insert(QString("endMonth"),QJsonValue(end.getMonth()));
        tour.insert(QString("endDay"),QJsonValue(end.getDay()));


        //-----------------------------------------
        QJsonArray matches;
        for(int j=0;j<b.getTours()[i].getTourMatches().size();j++){
            Match<int> m=b.getTours()[i].getTourMatches()[j];
            QJsonObject match;
            match.insert(QString("ID"),QJsonValue(m.getId()));

            MyDate hold=m.getHoldingDate();
            match.insert(QString("holdingDateYear"),QJsonValue(hold.getYear()));
            match.insert(QString("holdingDateMonth"),QJsonValue(hold.getMonth()));
            match.insert(QString("holdingDateDay"),QJsonValue(hold.getDay()));

            MyTime start=m.getStartTime();
            match.insert(QString("matchStartHour"),QJsonValue(start.getHour()));
            match.insert(QString("matchStartMin"),QJsonValue(start.getMin()));

            MyTime end=m.getEndTime();
            match.insert(QString("matchEndHour"),QJsonValue(end.getHour()));
            match.insert(QString("matchEndMin"),QJsonValue(end.getMin()));



            QJsonObject first;
            first.insert(QString("ID"),QJsonValue(m.getFirstTeamId()));
            int re=m.getFirstTeamResult();
            first.insert(QString("result"),QJsonValue(re));
            match.insert(QString("firstTeam"),QJsonValue(first));

            QJsonObject second;
            second.insert(QString("ID"),QJsonValue(m.getSecondTeamId()));
            int re2=m.getSecondTeamResult();
            second.insert(QString("result"),QJsonValue(re2));
            match.insert(QString("secondTeam"),QJsonValue(second));


            matches.push_back(QJsonValue(match));
        }
        tour.insert(QString("matches"),QJsonValue(matches));


        //------------------------------------------------
        QJsonArray ids;
        for(int j=0;j<b.getTours()[i].getTeamIDs().size();j++){
            ids.push_back(QJsonValue(b.getTours()[i].getTeamIDs()[j]));
        }
        tour.insert(QString("teamIDs"),QJsonValue(ids));


        tours.push_back(tour);
    }


    all.insert(QString("tours"),QJsonValue(tours));
    jsdoc.setObject(all);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeWrestling(QJsonDocument &jsdoc,Wrestling &b){
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    QJsonObject all = jsdoc.object();

    //-----------------------------------------------------
    Person host;
    QJsonObject jhost = all[QString("Host")].toObject();
    host.setFirstName(jhost["firstName"].toString());
    host.setLasName(all["lastName"].toString());
    host.setNationalCode(all["nationalCode"].toString());
    host.setGender(all["gender"].toBool());
    b.setHost(host);

    //----------------------------------------------------
    b.setUsername(all["username"].toString());
    b.setPassword(all["password"].toString());
    b.setFirstTime(all["firstTime"].toBool());

    //-----------------------------------------------------
    QJsonArray jteams=all["teams"].toArray();
    QVector<Team> teams;
    for(int i=0;i<jteams.size();i++){
        QJsonObject jteam=jteams[i].toObject();
        Team team;
        team.setID(jteam["ID"].toInt());
        team.setUsername(jteam["username"].toString());
        team.setPassword(jteam["password"].toString());
        team.setTeamName(jteam["teamName"].toString());
        team.setScore(jteam["score"].toInt());

        QJsonArray jmembers=jteam["members"].toArray();
        for(int j=0;j<jmembers.size();j++){
            Person member;
            QJsonObject jmember=jmembers[j].toObject();
            member.setFirstName(jmember["firstName"].toString());
            member.setLasName(jmember["lastName"].toString());
            member.setNationalCode(jmember["nationalCode"].toString());
            member.setGender(jmember["gender"].toBool());

            team.addPerson(member);
        }
        teams.push_back(team);
    }
    b.setTeams(teams);


    //--------------------------------------------------------
    QJsonArray jtours=all["tours"].toArray();
    QVector<Tournament<int>> tours;
    for(int i=0;i<jtours.size();i++){
        QJsonObject jtour=jtours[i].toObject();
        Tournament<int> tour;
        tour.setID(jtour["ID"].toInt());

        MyDate start;
        start.setYear(jtour["startYear"].toInt());
        start.setMonth(jtour["startMonth"].toInt());
        start.setDay(jtour["startDay"].toInt());
        tour.setTourStartDate(start);

        MyDate end;
        end.setYear(jtour["endYear"].toInt());
        end.setMonth(jtour["endMonth"].toInt());
        end.setDay(jtour["endDay"].toInt());
        tour.setTourStartDate(end);

        QJsonArray jmatches=jtour["matches"].toArray();
        QVector<Match<int>> matches;
        for(int j=0;j<jmatches.size();j++){
            QJsonObject jmatch=jmatches[i].toObject();
            Match<int> match;

            match.setID(jmatch["ID"].toInt());

            MyDate hold;
            hold.setYear(jmatch["holdingDateYear"].toInt());
            hold.setMonth(jmatch["holdingDateMonth"].toInt());
            hold.setDay(jmatch["holdingDateDay"].toInt());
            match.setHoldingDate(hold);

            MyTime start;
            start.setHour(jmatch["matchStartHour"].toInt());
            start.setMin(jmatch["matchStartMin"].toInt());
            match.setStart(start);

            MyTime end;
            end.setHour(jmatch["matchEndHour"].toInt());
            end.setMin(jmatch["matchEndMin"].toInt());
            match.setEnd(end);


            QJsonObject jfirst=jmatch["firstTeam"].toObject();
            match.setFirstTeamId(jfirst["ID"].toInt());
            int re=jfirst["result"].toInt();
            match.setFirstTeamResult(re);

            QJsonObject jsecond=jmatch["secondTeam"].toObject();
            match.setSecondTeamId(jsecond["ID"].toInt());
            int re2=jsecond["result"].toInt();
            match.setSecondTeamResult(re2);


            matches.push_back(match);
        }
        tour.setMatches(matches);

        QJsonArray jids=jtour["teamIDs"].toArray();
        QVector<int> ids;
        for(int j=0;j<jids.size();j++){
            ids.push_back(jids[i].toInt());
        }
        tour.setTeamIDs(ids);

        tours.push_back(tour);
    }
    b.setTours(tours);
}


void Start(Wrestling &w){
    QFile json(QString("Wrestling.json"));
    json.open(QFile::ReadOnly);
    QJsonDocument jsdoc=QJsonDocument().fromJson(json.readAll());
    makeWrestling(jsdoc,w);
    json.close();
}
void Update(const Wrestling &w){
    QJsonDocument doc;
    makeJson(doc,w);
    QFile json(QString("Wrestling.json"));
    json.open(QFile::WriteOnly);
    json.write(doc.toJson());
    json.close();
}
