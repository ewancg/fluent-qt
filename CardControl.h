#ifndef CARDCONTROL_H
#define CARDCONTROL_H

#include <QObject>
#include <QWidget>

#include "Control.h"

class CardControl : public Control {
 public:
  explicit CardControl(QWidget *parent = nullptr);

 protected:
  void paintEvent(QPaintEvent *event) override;
};

#endif  // CARDCONTROL_H
