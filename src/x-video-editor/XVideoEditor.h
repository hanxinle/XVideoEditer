#pragma once

#include <QtWidgets/QWidget>
#include "ui_XVideoEditor.h"

class XVideoEditor : public QWidget {

    Q_OBJECT

public:
    XVideoEditor(QWidget *parent = Q_NULLPTR);



public slots:
    void Open();
    void Set();


private:
    Ui::XVideoEditorClass ui;
};
