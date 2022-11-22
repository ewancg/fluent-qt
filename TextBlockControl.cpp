#include "TextBlockControl.h"

TextBlockControl::TextBlockControl(QWidget *parent) : Control(parent) {
  foregroundBrush = QColor("#FFFFFF");

  this->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
  this->setPadding(QMargins(0, 0, 0, 0));
}

void TextBlockControl::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintText(event, p);
}
