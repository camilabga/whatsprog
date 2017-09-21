#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char **argv)
{
  QApplication app (argc, argv);

  QWidget window;
    window.setFixedSize(400, 400);


    QPushButton *button = new QPushButton("OK!", &window);
    button->setGeometry(10, 10, 80, 30);

    QFont font ("Arial",24);
    button->setFont(font);
    button->setToolTip("Dica: encerre no 'X'");

    window.show();

  return app.exec();
}
