#include "CardControl.h"

CardControl::CardControl(QWidget *parent) : Control(parent) {
  m_background_brush = QColor("#0DFFFFFF");
  m_border_brush = QColor("#19000000");
}

void CardControl::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintBackground(event, p);
  //     paintText(event, p);
}
