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
  this->setFont(f);

  m_padding = QMargins(epx(11), epx(5), epx(11), epx(6));
  m_minimum_size = QSize(-1, -1);
}

void Control::evaluateMinimumSize(QPaintEvent *, QPainter &p) {
  if (!m_minimum_size.isValid()) {
    QSize innerSize = m_text.isEmpty()
                          ? QSize(m_padding.left() + m_padding.right(),
                                  m_padding.top() + m_padding.bottom())
                          : this->fontMetrics()
                                .boundingRect(QRect(), Qt::TextWordWrap, m_text)
                                .marginsAdded(m_padding)
                                .size();
    m_minimum_size =
        QSize((m_border_thickness * 2) +
                  std::max(m_border_outer_radius.minimumWidth<int>(),
                           innerSize.width()),
              (m_border_thickness * 2) +
                  std::max(m_border_outer_radius.minimumHeight<int>(),
                           innerSize.height()));
  }
  setMinimumSize(m_minimum_size);
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
            inset,                      inset,                      inset,          r.topLeft,      0);

    p.arcTo(inset,                      inset,                      r.topLeft,      r.topLeft,      180,    -90);
    p.arcTo(w - r.topRight - inset,     inset,                      r.topRight,     r.topRight,     90,     -90);
    p.arcTo(w - r.bottomRight - inset,  h - r.bottomRight - inset,  r.bottomRight,  r.bottomRight,  0,      -90);
    p.arcTo(inset,                      h - r.bottomLeft - inset,   r.bottomLeft,   r.bottomLeft,   270,    -90);
    p.arcTo(inset,                      inset,                      r.topLeft,      r.topLeft,      180,    0);
    // clang-format on
  };

  p.setCompositionMode(QPainter::CompositionMode_Plus);
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

  p.setPen(QPen(foregroundBrush, 0));
  p.drawText(this->rect().marginsRemoved(m_padding), m_alignment, m_text);
}

void Control::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintBackground(event, p);
  // paintText(event, p);
  evaluateMinimumSize(event, p);
}
