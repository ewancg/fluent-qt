#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H

#include <QEvent>
#include <QWidget>

#include "Control.h"

class ButtonControl : public Control {
  Q_OBJECT
 public:
  explicit ButtonControl(QWidget *parent = nullptr);

 signals:
  void pressed();
  void released();
  void toggled(bool);

 protected:
  //  void paintEvent(QPaintEvent *) override;

 private:
  bool isToggled = false;
  bool togglable = false;

  bool event(QEvent *evt) override;
  void paintEvent(QPaintEvent *event);
};

#endif  // BUTTONCONTROL_H
