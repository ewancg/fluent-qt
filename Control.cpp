#include "Control.h"

Control::Control(QWidget *parent) : QWidget{parent} {
  auto parentControl = qobject_cast<Control *>(this->parentWidget());
  if (parentControl && parentControl->brushes)
    brushes = parentControl->brushes;
  else
    brushes = new QHash<QString, QBrush>;

  QFont f;
  f.setFamily("Segoe UI Variable Text");
  f.setWeight(QFont::Weight::Normal);
  f.setPixelSize(epx(14));
  m_font = f;

  m_padding = QMargins(epx(11), epx(5), epx(11), epx(6));
  setProperty("border-thickness", 1);
  setProperty("border-radius", 4);
}

void Control::paintBackground(QPaintEvent *, QPainter &p) {
  const int border = epx(property("border-thickness").toDouble());
  // const QBrush borderBrush = brushes->find("border-brush").value();
  //  const QBrush backgroundBrush = brushes->find("background-brush").value();

  const int od = epx(property("border-radius").toDouble());
  const int id = od - border;

  p.setRenderHint(QPainter::Antialiasing);

  QPainterPath path, path2;

  path.addRoundedRect(this->rect(), od, od);
  path2.addRoundedRect(this->rect().marginsRemoved(mg(border)), id, id);

  p.setPen(Qt::NoPen);
  p.setBrush(borderBrush);
  p.drawPath(path.subtracted(path2));
  p.setBrush(backgroundBrush);
  p.drawPath(path2.intersected(path));
}

void Control::paintText(QPaintEvent *, QPainter &p) {
  p.setRenderHint(QPainter::TextAntialiasing);

  const auto originalFont = p.font();
  p.setFont(m_font);

  p.setPen(QPen(foregroundBrush, 0));
  this->setMinimumSize(p.fontMetrics()
                           .boundingRect(QRect(), Qt::TextWordWrap, m_text)
                           .marginsAdded(m_padding)
                           .size());

  p.drawText(this->rect().marginsRemoved(m_padding), m_alignment, m_text);
  p.setFont(originalFont);
}

void Control::paintEvent(QPaintEvent *event) {
  // QPainter p(this);
  // paintBackground(event, p);
  // paintText(event, p);
}
