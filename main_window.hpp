#pragma once
#include "ui_main_window.h"
#include <QWidget>

class MainWindow: public QWidget, public Ui::MainWindow
{
Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
private:
  void generate();
  int x;
  int y;
  int res;
  int level = 1;
  double experience = 0.0;
private slots:
  void but_clicked();
  void butBckSpc_clicked();
  void butCR_clicked();
};
