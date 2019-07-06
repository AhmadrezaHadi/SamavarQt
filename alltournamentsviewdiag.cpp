#include "alltournamentsviewdiag.h"


allTournamentsViewDiag::allTournamentsViewDiag(int type, bool adminAccess, QWidget *parent) :
    QDialog(parent)
{
    tourList = new QListWidget;
    QPushButton * closeButton = new QPushButton;
    QPushButton * editTourButton = new QPushButton;
    QPushButton * tourInfoButton = new QPushButton;
    QVBoxLayout * vBox =  new QVBoxLayout;
    QHBoxLayout * hBox = new QHBoxLayout;
    QLabel * pageLabel = new QLabel;


    pageLabel->setText("All Tournaments");
    closeButton->setText("CLOSE");
    editTourButton->setText("Edit");
    tourInfoButton->setText("Show Info");

    //connect
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed()));
    connect(editTourButton, SIGNAL(clicked(bool)), this, SLOT(editTourButtonPressed()));
    connect(tourInfoButton, SIGNAL(clicked(bool)), this, SLOT(tourInfoButtonPressed()));

    tourList->addItem("Number\tTour ID\tStarting Month\tStarting Day\tEnd month\tEnd Day");
    if (type == 0){
        for (int i = 0; i < bbvb.getTours().size(); ++i){
            tourList->addItem(QString::number(i+1) +
                              "\t" + bbvb.getTours()[i].getTourId() +
                              "\t" + bbvb.getTours()[i].getTourStartDate().getMonth() +
                              "\t" + bbvb.getTours()[i].getTourStartDate().getDay() +
                              "\t" + bbvb.getTours()[i].getTourEndDate().getMonth() +
                              "\t" + bbvb.getTours()[i].getTourEndDate().getDay());
            // complete this fucking shit

        }
    }else if (type == 1){
        for (int i = 0; i < pp.getTours().size(); ++i){
            tourList->addItem(QString::number(i+1) +
                              "\t" + pp.getTours()[i].getTourId() +
                              "\t" + pp.getTours()[i].getTourStartDate().getMonth() +
                              "\t" + pp.getTours()[i].getTourStartDate().getDay() +
                              "\t" + pp.getTours()[i].getTourEndDate().getMonth() +
                              "\t" + pp.getTours()[i].getTourEndDate().getDay());
            // complete this fucking shit

        }
    }else if (type == 2){
        for (int i = 0; i < wr.getTours().size(); ++i){
            tourList->addItem(QString::number(i+1) +
                              "\t" + wr.getTours()[i].getTourId() +
                              "\t" + wr.getTours()[i].getTourStartDate().getMonth() +
                              "\t" + wr.getTours()[i].getTourStartDate().getDay() +
                              "\t" + wr.getTours()[i].getTourEndDate().getMonth() +
                              "\t" + wr.getTours()[i].getTourEndDate().getDay());
            //TODO complete this fucking shit

        }
    }

    if (adminAccess){

    }else{

    }


}

allTournamentsViewDiag::~allTournamentsViewDiag()
{

}

void allTournamentsViewDiag::editTourButtonPressed()
{

}


void allTournamentsViewDiag::closeButtonPressed()
{
    this->close();
}



void allTournamentsViewDiag::tourInfoButtonPressed()
{

}
