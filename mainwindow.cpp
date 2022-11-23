#include "mainwindow.h"

#include <windows.h>

#include <QtDebug>
#include <QtMath>

#include "./ui_mainwindow.h"
#include "dwmapi.h"  // only needed for margins. ugh

#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#define DWMWA_SYSTEMBACKDROP_TYPE 38

#pragma comment(lib, "dwmapi.lib")

// #include "windows.ui.viewmanagement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_NoSystemBackground, true);
  setAttribute(Qt::WA_OpaquePaintEvent, false);

  // Windows::UI::UISettings s;

  // auto accent = UISettings().GetColorValue(AccentLight1);

  QTimer::singleShot(0, this, [this] {
    auto hwnd = reinterpret_cast<HWND>(this->winId());

    BOOL dark = true;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark,
                          sizeof(dark));

    MARGINS margins = {-1};
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    auto cycle = [=] {
      static auto param = 1;
      param < 4 ? param++ : param = 1;

      int DWMSBT_MAINWINDOW = param;
      DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &DWMSBT_MAINWINDOW,
                            sizeof(DWMSBT_MAINWINDOW));
    };
    // connect(ui->button, &ButtonControl::released, this, cycle);
    cycle();
  });

  ui->button->setText("Click Me");
  ui->button_3->setBorderThickness(3);
  ui->button_3->setBorderRadius(12, 24, 12, 6);
  ui->button_3->m_border_brush = QColor("#88fc4a88");

  QColor m_border_brush = Qt::red;
  m_border_brush.setAlphaF(0.5);
  ui->widget_2->m_border_brush = m_border_brush;

  QColor m_background_brush = Qt::blue;
  m_background_brush.setAlphaF(0.5);
  ui->widget_2->m_background_brush = m_background_brush;

  ui->widget_2->setBorderRadius(10, 20, 30, 40);
  ui->widget_2->setBorderThickness(4);

  ui->bourt->setBorderRadius(0);

  ui->button_4->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
  //  ui->button_4->setText("Combo Boxin");
  ui->button_4->setGlyph(QChar(0xe70d));

  ui->textBlock->setText(
      "zzzzzzzzzzzzzzzzz\nzzzzzzzzzzzzzzzzzzzzzzzzzz\nzzzzzzzzzzzzzzzzzzzzzzzzo"
      "oz");
  connect(ui->button, &ButtonControl::released, this, [this] {
    ui->button->setText("Bazoobledorpf");
    ui->button->update();
  });
}

MainWindow::~MainWindow() { delete ui; }
