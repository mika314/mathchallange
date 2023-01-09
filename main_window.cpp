#include "main_window.hpp"
#include <QDebug>
#include <fstream>

MainWindow::MainWindow(QWidget *parent):
  QWidget(parent)
{
  setupUi(this);
  std::ifstream save("save.txt");
  if (save)
    save >> level >> experience;
  
  srand(time(nullptr));
  connect(but0, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but1, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but2, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but3, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but4, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but5, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but6, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but7, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but8, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(but9, SIGNAL(clicked()), this, SLOT(but_clicked()));
  connect(butBckSpc, SIGNAL(clicked()), this, SLOT(butBckSpc_clicked()));
  connect(butCR, SIGNAL(clicked()), this, SLOT(butCR_clicked()));
  generate();
}

int intPow(int x,  int y)
{
  auto res = 1;
  for (auto i = 0; i < y; ++i)
    res *= x;
  return res;
}

void MainWindow::generate()
{
  qDebug() << (intPow(10, level) - 2);
  x = rand() % (intPow(10, level) - 2) + 2;
  qDebug() << (intPow(10, level - log10(x) + 1) - 2);
  y = rand() % (intPow(10, level - log10(x) + 1) - 2) + 2;
  res = 0;
  Ui::MainWindow::x->setText(QString::number(x));
  Ui::MainWindow::y->setText(QString::number(y));
  Ui::MainWindow::res->setText(QString::number(res));
  Ui::MainWindow::level->setText("Level: " + QString::number(level));
  Ui::MainWindow::experience->setValue(experience);
}

void MainWindow::but_clicked()
{
  res *= 10;
  res += (sender()->objectName()[3].unicode() - L'0');
  Ui::MainWindow::res->setText(QString::number(res));
}

void MainWindow::butBckSpc_clicked()
{
  res /= 10;
  Ui::MainWindow::res->setText(QString::number(res));
}

void MainWindow::butCR_clicked()
{
  if (x * y == res)
  {
    experience += 30.0 * (log10(1.0 * x) + log10(1.0 * y)) / level;
    qDebug() << 30.0 * (log10(1.0 * x) + log10(1.0 * y)) / level;
    if (experience > 1000)
    {
      experience -= 1000;
      ++level;
    }
    std::ofstream save("save.txt");
    if (save)
      save << level << " " << experience;
    generate();
  }
}
