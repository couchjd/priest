#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_toolkit.h"

class toolkit : public QMainWindow
{
    Q_OBJECT

public:
    toolkit(QWidget *parent = Q_NULLPTR);

private:
    Ui::toolkitClass ui;
};
