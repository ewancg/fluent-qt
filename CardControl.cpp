#include "CardControl.h"

CardControl::CardControl(QWidget *parent) : Control(parent) {
  backgroundBrush = QColor("#0DFFFFFF");
  borderBrush = QColor("#19000000");
}

void CardControl::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintBackground(event, p);
  //     paintText(event, p);
}
