#ifndef TEXTBLOCKCONTROL_H
#define TEXTBLOCKCONTROL_H

#include <QObject>
#include <QWidget>

#include "Control.h"

class TextBlockControl : public Control {
  Q_OBJECT
 public:
  explicit TextBlockControl(QWidget *parent = nullptr);

 protected:
  void paintEvent(QPaintEvent *event) override;
};

#endif  // TEXTBLOCKCONTROL_H
