#include "widget.h"
#include <QComboBox>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>
#include <QDebug>
#include <QVBoxLayout>

TestWidget::TestWidget()
{
    qDebug() << "start.";
    QComboBox* scheme = new QComboBox;
    scheme->addItems({"1","2"});
    connect(scheme, &QComboBox::currentTextChanged,this,[](){ qDebug() << "emit currentTextChanged.";});
    connect(scheme, QOverload<int>::of(&QComboBox::currentIndexChanged),this,[](int index){ qDebug() << "emit currentIndexChanged.";});

    QLineEdit* letter = new QLineEdit("111");
    connect(letter, &QLineEdit::editingFinished,this,[](){ qDebug() << "emit editingFinished.";});
    connect(letter, &QLineEdit::textChanged,this,[](){ qDebug() << "emit textChanged.";});
    connect(letter, &QLineEdit::textEdited,this,[](){ qDebug() << "emit textEdited.";});

    QCheckBox* choose = new QCheckBox("choose");
    choose->setChecked(false);
    connect(choose, &QCheckBox::toggled,this,[](){ qDebug() << "emit toggled.";});

    QButtonGroup* buttonGroup = new QButtonGroup(this);
    QRadioButton* btn1 = new QRadioButton("left");
    QRadioButton* btn2 = new QRadioButton("mid");
    QRadioButton* btn3 = new QRadioButton("right");
    btn1->setChecked(true);
    buttonGroup->addButton(btn1,0);
    buttonGroup->addButton(btn2,1);
    buttonGroup->addButton(btn3,2);
    buttonGroup->setExclusive(true);
    connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),this,[](int index){ qDebug() << "emit buttonClicked.";});
    connect(buttonGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled),this,[](int t1,bool t2){ qDebug() << "emit buttonToggled."<<t1<<","<<t2;});

    scheme->setCurrentText("1");
    letter->setText("222");
    choose->setChecked(true);
    btn2->setChecked(true);
    btn3->setChecked(true);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(scheme);
    mainLayout->addWidget(letter);
    mainLayout->addWidget(choose);
    mainLayout->addWidget(btn1);
    mainLayout->addWidget(btn2);
    mainLayout->addWidget(btn3);
    mainLayout->addStretch();
    this->setLayout(mainLayout);
    this->setFixedSize(400,200);

}

TestWidget::~TestWidget()
{

}
