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
}

void Control::paintBackground(QPaintEvent *, QPainter &p) {
  if (!m_border_outer_radius.isValid())
    m_border_outer_radius = epx(m_border_radius);
  if (!m_border_inner_radius.isValid())
    m_border_inner_radius = m_border_outer_radius - m_border_thickness;

  p.setRenderHint(QPainter::Antialiasing);

  QPainterPath path, path2;

  const int w = width();
  const int h = height();

  auto drawRoundedRect = [this, w, h](QPainterPath &p, const BorderRadius &r,
                                      int inset) {
    // clang-format off
    p.arcMoveTo(
            inset,                      inset,                      r.topLeft,      r.topLeft,      0);

    p.arcTo(inset,                      inset,                      r.topLeft,      r.topLeft,      180,    -90);
    p.arcTo(w - r.topRight - inset,     inset,                      r.topRight,     r.topRight,     90,     -90);
    p.arcTo(w - r.bottomRight - inset,  h - r.bottomRight - inset,  r.bottomRight,  r.bottomRight,  0,      -90);
    p.arcTo(inset,                      h - r.bottomLeft - inset,   r.bottomLeft,   r.bottomLeft,   270,    -90);
    p.arcTo(inset,                      inset,                      r.topLeft,      r.topLeft,      180,    0);
    // clang-format on
  };

  drawRoundedRect(path, m_border_outer_radius, 0);
  drawRoundedRect(path2, m_border_inner_radius, epx(m_border_thickness));

  p.setPen(Qt::NoPen);
  p.setBrush(m_border_brush);
  p.drawPath(path.subtracted(path2));
  p.setBrush(m_background_brush);
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
  QPainter p(this);
  paintBackground(event, p);
  // paintText(event, p);
}
