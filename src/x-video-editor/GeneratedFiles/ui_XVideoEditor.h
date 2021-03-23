/********************************************************************************
** Form generated from reading UI file 'XVideoEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOEDITOR_H
#define UI_XVIDEOEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "xvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_XVideoEditorClass
{
public:
    XVideoWidget *src;
    QPushButton *openButton;
    XVideoWidget *dst;
    QSpinBox *bright;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *contact;
    QPushButton *setButton;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *rotateBox;
    QComboBox *flipBox;
    QSpinBox *height;
    QLabel *label_5;
    QSpinBox *width;

    void setupUi(QWidget *XVideoEditorClass)
    {
        if (XVideoEditorClass->objectName().isEmpty())
            XVideoEditorClass->setObjectName(QString::fromUtf8("XVideoEditorClass"));
        XVideoEditorClass->resize(797, 634);
        XVideoEditorClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 250, 255);"));
        src = new XVideoWidget(XVideoEditorClass);
        src->setObjectName(QString::fromUtf8("src"));
        src->setGeometry(QRect(20, 30, 360, 240));
        openButton = new QPushButton(XVideoEditorClass);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(120, 330, 111, 30));
        openButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        dst = new XVideoWidget(XVideoEditorClass);
        dst->setObjectName(QString::fromUtf8("dst"));
        dst->setGeometry(QRect(420, 30, 360, 240));
        bright = new QSpinBox(XVideoEditorClass);
        bright->setObjectName(QString::fromUtf8("bright"));
        bright->setGeometry(QRect(410, 330, 40, 20));
        bright->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        label = new QLabel(XVideoEditorClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(381, 330, 24, 16));
        label_2 = new QLabel(XVideoEditorClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 330, 81, 20));
        contact = new QSpinBox(XVideoEditorClass);
        contact->setObjectName(QString::fromUtf8("contact"));
        contact->setGeometry(QRect(550, 330, 40, 20));
        contact->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        contact->setMaximum(3);
        setButton = new QPushButton(XVideoEditorClass);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setGeometry(QRect(120, 520, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        setButton->setFont(font);
        setButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"font: 9pt \"Adobe Devanagari\";"));
        label_3 = new QLabel(XVideoEditorClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(382, 402, 48, 16));
        label_4 = new QLabel(XVideoEditorClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 450, 61, 20));
        rotateBox = new QComboBox(XVideoEditorClass);
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->setObjectName(QString::fromUtf8("rotateBox"));
        rotateBox->setGeometry(QRect(490, 402, 69, 20));
        rotateBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        flipBox = new QComboBox(XVideoEditorClass);
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->setObjectName(QString::fromUtf8("flipBox"));
        flipBox->setGeometry(QRect(490, 450, 69, 20));
        flipBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        height = new QSpinBox(XVideoEditorClass);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(560, 520, 40, 20));
        height->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        height->setMaximum(999);
        label_5 = new QLabel(XVideoEditorClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 520, 111, 16));
        width = new QSpinBox(XVideoEditorClass);
        width->setObjectName(QString::fromUtf8("width"));
        width->setGeometry(QRect(490, 520, 40, 20));
        width->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 0);"));
        width->setMaximum(999);

        retranslateUi(XVideoEditorClass);
        QObject::connect(openButton, SIGNAL(clicked()), XVideoEditorClass, SLOT(Open()));
        QObject::connect(setButton, SIGNAL(clicked()), XVideoEditorClass, SLOT(Set()));

        QMetaObject::connectSlotsByName(XVideoEditorClass);
    } // setupUi

    void retranslateUi(QWidget *XVideoEditorClass)
    {
        XVideoEditorClass->setWindowTitle(QApplication::translate("XVideoEditorClass", "XVideoEditor", nullptr));
        openButton->setText(QApplication::translate("XVideoEditorClass", "\346\211\223\345\274\200\350\247\206\351\242\221", nullptr));
        label->setText(QApplication::translate("XVideoEditorClass", "\344\272\256\345\272\246", nullptr));
        label_2->setText(QApplication::translate("XVideoEditorClass", "\345\257\271\346\257\224\345\272\246", nullptr));
        setButton->setText(QApplication::translate("XVideoEditorClass", "\345\272\224\347\224\250\345\217\263\344\276\247\350\256\276\347\275\256", nullptr));
        label_3->setText(QApplication::translate("XVideoEditorClass", "\345\233\276\345\203\217\346\227\213\350\275\254", nullptr));
        label_4->setText(QApplication::translate("XVideoEditorClass", "\345\233\276\345\203\217\351\225\234\345\203\217", nullptr));
        rotateBox->setItemText(0, QApplication::translate("XVideoEditorClass", "0", nullptr));
        rotateBox->setItemText(1, QApplication::translate("XVideoEditorClass", "90\302\260", nullptr));
        rotateBox->setItemText(2, QApplication::translate("XVideoEditorClass", "180\302\260", nullptr));
        rotateBox->setItemText(3, QApplication::translate("XVideoEditorClass", "270\302\260", nullptr));

        flipBox->setItemText(0, QApplication::translate("XVideoEditorClass", "\344\270\215\346\224\271\345\217\230", nullptr));
        flipBox->setItemText(1, QApplication::translate("XVideoEditorClass", "\344\270\212\344\270\213", nullptr));
        flipBox->setItemText(2, QApplication::translate("XVideoEditorClass", "\345\267\246\345\217\263", nullptr));
        flipBox->setItemText(3, QApplication::translate("XVideoEditorClass", "\344\270\212\344\270\213\345\222\214\345\267\246\345\217\263", nullptr));

        label_5->setText(QApplication::translate("XVideoEditorClass", "\345\233\276\345\203\217\345\260\272\345\257\270\357\274\210\345\256\275\357\274\214\351\253\230\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XVideoEditorClass: public Ui_XVideoEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOEDITOR_H
