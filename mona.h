#ifndef MONA_H
#define MONA_H

#include <QMainWindow>

namespace Ui {
class mona;
}

class mona : public QMainWindow
{
    Q_OBJECT

public:
    explicit mona(QWidget *parent = nullptr);
    ~mona();

private:
    Ui::mona *ui;

public slots:
    void caldmg();
};


#endif // MONA_H
