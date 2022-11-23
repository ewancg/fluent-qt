#include "ComboBoxControl.h"

ComboBoxControl::ComboBoxControl(QWidget *parent) : ButtonControl(parent) {}

void ComboBoxControl::paintChevron(QPaintEvent *, QPainter &p) {
  p.setRenderHint(QPainter::TextAntialiasing);

  const auto originalFont = p.font();
  QFont f = p.font();
  f.setFamily("Segoe Fluent Icons");
  p.setFont(f);

  p.setPen(QPen(foregroundBrush, 0));
  static bool chevronAccounted = false;

  QSize s = p.fontMetrics()
                .boundingRect(QRect(), Qt::TextWordWrap, m_text)
                .marginsAdded(m_padding)
                .size();
  this->setMinimumSize(s);

  if (!chevronAccounted) {
    m_padding.setRight(m_padding.right() * 2 + s.width());
    chevronAccounted = true;
  }

  p.drawText(this->rect().marginsRemoved(m_padding),
             Qt::AlignRight | Qt::AlignVCenter, m_glyph);
  p.setFont(originalFont);

  // it's borked
}

void ComboBoxControl::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintBackground(event, p);
  paintText(event, p);
  paintChevron(event, p);
  evaluateMinimumSize(event, p);
}
