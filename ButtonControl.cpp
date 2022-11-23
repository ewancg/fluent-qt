#include "ButtonControl.h"

ButtonControl::ButtonControl(QWidget *parent) : Control(parent) {
  brushes->insert("button-background-brush-idle", QColor("#0FFFFFFF"));
  brushes->insert("button-background-brush-hover", QColor("#15FFFFFF"));
  brushes->insert("button-background-brush-pressed", QColor("#08FFFFFF"));

  brushes->insert("button-foreground-brush-idle", QColor("#FFFFFF"));
  brushes->insert("button-foreground-brush-hover", QColor("#FFFFFF"));
  brushes->insert("button-foreground-brush-pressed", QColor("#C5FFFFFF"));

  QLinearGradient g(0, 0, 0, epx(3));
  g.setColorAt(epx(0.33), QColor("#18FFFFFF"));
  g.setColorAt(epx(1), QColor("#12FFFFFF"));
  m_border_brush = g;

  //  brushes->insert("button-border-brush-idle", g);

  brushes->insert("border-brush", QBrush(g));
  //  brushes->insert("background-brush",
  //                  brushes->find("button-background-brush-idle").value());

  //  brushes->insert("foreground-brush",
  //                  brushes->find("button-foreground-brush-idle").value());

  backgroundAnimation.setDuration(83);
  m_background_brush =
      brushes->find("button-background-brush-idle").value().color();
  connect(&backgroundAnimation, &QVariantAnimation::valueChanged, this, [this] {
    m_background_brush = QColor(backgroundAnimation.currentValue().toString());
    update();
  });

  foregroundAnimation.setDuration(83);
  foregroundBrush =
      brushes->find("button-foreground-brush-idle").value().color();
  connect(&foregroundAnimation, &QVariantAnimation::valueChanged, this, [this] {
    foregroundBrush = QColor(foregroundAnimation.currentValue().toString());
    update();
  });
}

bool ButtonControl::event(QEvent *evt) {
  static auto updateState = [this](QVariantAnimation &anim,
                                   const QString &first, const QString &last) {
    if (anim.state() == QVariantAnimation::Running) anim.stop();
    anim.setStartValue(brushes->find(first).value().color());
    anim.setEndValue(brushes->find(last).value().color());
    anim.start();
  };

  switch (evt->type()) {
    case QEvent::MouseButtonPress: {
      emit(pressed());
      if (togglable) {
        isToggled = !isToggled;
        emit(toggled(isToggled));
      } else {
        updateState(backgroundAnimation, "button-background-brush-hover",
                    "button-background-brush-pressed");
        updateState(foregroundAnimation, "button-foreground-brush-hover",
                    "button-foreground-brush-pressed");
      }
      return false;
    }
    case QEvent::MouseButtonRelease: {
      emit(released());
      updateState(backgroundAnimation, "button-background-brush-pressed",
                  "button-background-brush-hover");
      updateState(foregroundAnimation, "button-foreground-brush-pressed",
                  "button-foreground-brush-hover");
      return false;
    }
    case QEvent::Enter: {
      updateState(backgroundAnimation, "button-background-brush-idle",
                  "button-background-brush-hover");
      updateState(foregroundAnimation, "button-foreground-brush-idle",
                  "button-foreground-brush-hover");
      return false;
    }
    case QEvent::Leave: {
      updateState(backgroundAnimation, "button-background-brush-hover",
                  "button-background-brush-idle");
      updateState(foregroundAnimation, "button-foreground-brush-hover",
                  "button-foreground-brush-idle");
      return false;
    }
    default:
      return QWidget::event(evt);
  }
}

void ButtonControl::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  paintBackground(event, p);
  paintText(event, p);
}
