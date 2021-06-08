/********************************************************************************
** Form generated from reading UI file 'guidescene.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDESCENE_H
#define UI_GUIDESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guidescene
{
public:
    QWidget *centralwidget;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QDateTimeEdit *dateTimeEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guidescene)
    {
        if (guidescene->objectName().isEmpty())
            guidescene->setObjectName(QString::fromUtf8("guidescene"));
        guidescene->resize(1200, 911);
        guidescene->setMinimumSize(QSize(0, 582));
        guidescene->setMaximumSize(QSize(1300, 16777215));
        centralwidget = new QWidget(guidescene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(1000, 30, 101, 21));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1000, 280, 141, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(860, 20, 101, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1000, 110, 101, 31));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1000, 190, 101, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(910, 100, 51, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(910, 190, 51, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(870, 280, 101, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(870, 370, 101, 31));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(1000, 450, 101, 22));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(840, 450, 141, 31));
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(1000, 370, 101, 22));
        guidescene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guidescene);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        guidescene->setMenuBar(menubar);
        statusbar = new QStatusBar(guidescene);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        guidescene->setStatusBar(statusbar);

        retranslateUi(guidescene);

        QMetaObject::connectSlotsByName(guidescene);
    } // setupUi

    void retranslateUi(QMainWindow *guidescene)
    {
        guidescene->setWindowTitle(QCoreApplication::translate("guidescene", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("guidescene", "\346\234\200\347\237\255\350\267\235\347\246\273\347\255\226\347\225\245", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("guidescene", "\346\234\200\347\237\255\346\227\266\351\227\264\347\255\226\347\225\245", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("guidescene", "\351\200\224\345\276\204\346\234\200\347\237\255\350\267\235\347\246\273\347\255\226\347\225\245", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("guidescene", "\344\272\244\351\200\232\345\267\245\345\205\267\346\234\200\347\237\255\346\227\266\351\227\264\347\255\226\347\225\245", nullptr));

        label->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\345\207\272\345\217\221\346\227\266\351\227\264</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\350\265\267\347\202\271</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\347\273\210\347\202\271</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\345\257\274\350\210\252\347\255\226\347\225\245</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\345\210\260\350\276\276\346\227\266\351\227\264</span></p></body></html>", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("guidescene", "\351\243\237\345\240\202", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("guidescene", "\346\225\231\345\255\246\346\245\274", nullptr));

        label_6->setText(QCoreApplication::translate("guidescene", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">\346\237\245\350\257\242\345\221\250\345\233\264\346\234\215\345\212\241\350\256\276\346\226\275</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guidescene: public Ui_guidescene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDESCENE_H
