#include "scanplot.h"
#include <string>
#include <QString>
#include <QStyle>

ScanPlot::ScanPlot(QWidget *parent)
    : QWidget(parent)
{
    scan = new LTDHWScan;
    std::string filename = "example_scan.csv";
    reader = new LTDHWScanReader(scan, filename);

    svgWidget = new QSvgWidget("C:\\Users\\zhangxiaoyu\\Desktop\\squirrelfish-lives.svg", this);

    createButtons();
    createInfos();

    //connect();

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(toolBarLayout);
    mainLayout->addWidget(svgWidget);
    mainLayout->addLayout(attrLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Movie Player"));
    resize(600, 400);
}

ScanPlot::~ScanPlot()
{

}

void ScanPlot::createButtons()
{
    QSize iconSize(20, 20);

    backButton = new QToolButton;
    //backButton->setIcon(style()->standardIcon(QStyle::SP_ArrowBack));
    backButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\backward.svg"));
    backButton->setIconSize(iconSize);
    backButton->setToolTip(tr("Backward"));
    // connect(backButton, SIGNAL(clicked()), this, SLOT(open()));

    forwardButton = new QToolButton;
    forwardButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\forward.svg"));
    forwardButton->setIconSize(iconSize);
    forwardButton->setToolTip(tr("Forward"));
    // connect(forwardButton, SIGNAL(clicked()), this, SLOT(open()));

    zoomInButton = new QToolButton;
    zoomInButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\zoom in.svg"));
    zoomInButton->setIconSize(iconSize);
    zoomInButton->setToolTip(tr("Zoom In"));
    // connect(zoomInButton, SIGNAL(clicked()), this, SLOT(open()));

    zoomOutButton = new QToolButton;
    zoomOutButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\zoom out.svg"));
    zoomOutButton->setIconSize(iconSize);
    zoomOutButton->setToolTip(tr("Zoom Out"));
    // connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(open()));

    fitScreenButton = new QToolButton;
    fitScreenButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\screen-full.svg"));
    fitScreenButton->setIconSize(iconSize);
    fitScreenButton->setToolTip(tr("Screen Full"));
    // connect(fitScreenButton, SIGNAL(clicked()), this, SLOT(open()));

    refreshButton = new QToolButton;
    refreshButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\refresh.svg"));
    refreshButton->setIconSize(iconSize);
    refreshButton->setToolTip(tr("Refresh"));
    // connect(refreshButton, SIGNAL(clicked()), this, SLOT(open()));

    openButton = new QToolButton;
    openButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\open_in_new.svg"));
    openButton->setIconSize(iconSize);
    openButton->setToolTip(tr("Open In New"));
    // connect(openButton, SIGNAL(clicked()), this, SLOT(open()));

    helpButton = new QToolButton;
    helpButton->setIcon(QIcon("D:\\qtTest\\eyescan\\icons\\info.svg"));
    helpButton->setIconSize(iconSize);
    helpButton->setToolTip(tr("Help"));
    // connect(helpButton, SIGNAL(clicked()), this, SLOT(open()));

    svgType = new QComboBox;
    svgType->insertItem(0, "Contour (Filled)", SVG_CONTOUR_FILLED);
    svgType->insertItem(1, "Contour (Lines)", SVG_CONTOUR_NOFILL);
    svgType->insertItem(2, "Bathtub (Central Horizontal line)", SVG_BATHTUB);
    svgType->insertItem(3, "Heat map", SVG_HEATMAP);

    SVG_Types type = (SVG_Types)(svgType->currentIndex());
    connect(svgType, SIGNAL(currentIndexChanged(int)), this, SLOT(svgChange(int)));

    toolBarLayout = new QHBoxLayout;
    toolBarLayout->addWidget(backButton);
    toolBarLayout->addWidget(forwardButton);
    toolBarLayout->addWidget(zoomInButton);
    toolBarLayout->addWidget(zoomOutButton);
    toolBarLayout->addWidget(fitScreenButton);
    toolBarLayout->addWidget(refreshButton);
    toolBarLayout->addWidget(openButton);
    toolBarLayout->addWidget(helpButton);
    toolBarLayout->addWidget(svgType);
}

void ScanPlot::svgChange(int type)
{
    if (type == 0) {
        svgWidget->load(QString("C:\\Users\\zhangxiaoyu\\Desktop\\squirrelfish-lives.svg"));
    } else if (type == 1) {
        svgWidget->load(QString("C:\\Users\\zhangxiaoyu\\Desktop\\Mahuri.svg"));
    } else if (type == 2) {
        svgWidget->load(QString("C:\\Users\\zhangxiaoyu\\Desktop\\bw_paint.svg"));
    } else {
        svgWidget->load(QString("C:\\Users\\zhangxiaoyu\\Desktop\\Ghostscript_Tiger.svg"));
    }
}

void ScanPlot::createInfos()
{
    attrLayout = new QGridLayout;
    attrLayout->setSpacing(10);

    // description
    QLabel* sm_title = new QLabel(QString("Summary"));
    QFrame* sm_line = new QFrame(this);
    sm_line->setFrameShape(QFrame::HLine);
    sm_line->setFrameShadow(QFrame::Plain);

    QLabel* sm_name = new QLabel(QString("  Name:"));
    QLabel* sm_dscp = new QLabel(QString("  Description:"));
    QLabel* sm_start = new QLabel(QString("  Started:"));
    QLabel* sm_end = new QLabel(QString("  Ended:"));
    QLabel* scan_name = new QLabel(QString::fromStdString(reader->descr_str_0xa0));
    QLabel* scan_dscp = new QLabel(QString::fromStdString(reader->descr_str_0xa0));
    QLabel* start_tm = new QLabel(QString::fromStdString(reader->time_started_str_0x60));
    QLabel* end_tm = new QLabel(QString::fromStdString(reader->time_ended_str_0x80));

    attrLayout->addWidget(sm_title, 0, 0, 1, 4);
    attrLayout->addWidget(sm_line, 1, 0, 1, 4);
    attrLayout->addWidget(sm_name, 2, 0, 1, 1);
    attrLayout->addWidget(sm_dscp, 3, 0, 1, 1);
    attrLayout->addWidget(sm_start, 4, 0, 1, 1);
    attrLayout->addWidget(sm_end, 5, 0, 1, 1);
    attrLayout->addWidget(scan_name, 2, 1, 1, 3);
    attrLayout->addWidget(scan_dscp, 3, 1, 1, 3);
    attrLayout->addWidget(start_tm, 4, 1, 1, 3);
    attrLayout->addWidget(end_tm, 5, 1, 1, 3);

    // metrics
    QLabel* mt_title = new QLabel(QString("Metrics"));
    QFrame* mt_line = new QFrame(this);
    mt_line->setFrameShape(QFrame::HLine);
    mt_line->setFrameShadow(QFrame::Plain);

    QLabel* mt_op_area = new QLabel("  Open Area:");
    QLabel* mt_op_ui = new QLabel(QString("  Open UI %:"));
    QLabel* scan_op_area = new QLabel(QString::fromStdString(reader->open_area_str_0x100));
    QLabel* scan_op_ui = new QLabel(QString::fromStdString(reader->horiz_perc_str_0x140));

    attrLayout->addWidget(mt_title, 0, 4, 1, 2);
    attrLayout->addWidget(mt_line, 1, 4, 1, 2);
    attrLayout->addWidget(mt_op_area, 2, 4, 1, 1);
    attrLayout->addWidget(mt_op_ui, 3, 4, 1, 1);
    attrLayout->addWidget(scan_op_area, 2, 5, 1, 1);
    attrLayout->addWidget(scan_op_ui, 3, 5, 1, 1);

    // settings
    QLabel* st_title = new QLabel(QString("Settings"));
    QFrame* st_line = new QFrame(this);
    st_line->setFrameShape(QFrame::HLine);
    st_line->setFrameShadow(QFrame::Plain);

    QLabel* st_lk_setting = new QLabel(QString("  Link settings:"));
    QLabel* st_hz_inc = new QLabel(QString("  Horizontal increment:"));
    QLabel* st_hz_range = new QLabel(QString("  Horizontal range:"));
    QLabel* st_vt_inc = new QLabel(QString("  Vertical increment:"));
    QLabel* st_vt_range = new QLabel(QString("  Vertical range:"));
    QLabel* lk_setting = new QLabel(QString::fromStdString(reader->link_settings_str_0xc0));
    QLabel* horz_inc = new QLabel(QString::fromStdString(reader->horz_incr_str_0x200));
    QLabel* horz_range = new QLabel(QString::fromStdString(reader->horz_range_str_0x220));
    QLabel* vert_inc = new QLabel(QString::fromStdString(reader->vertical_incr_str_0x240));
    QLabel* vert_range = new QLabel(QString::fromStdString(reader->vertical_range_str_0x260));

    attrLayout->addWidget(st_title, 0, 6, 1, 4);
    attrLayout->addWidget(st_line, 1, 6, 1, 4);
    attrLayout->addWidget(st_lk_setting, 2, 6, 1, 2);
    attrLayout->addWidget(st_hz_inc, 3, 6, 1, 2);
    attrLayout->addWidget(st_hz_range, 4, 6, 1, 2);
    attrLayout->addWidget(st_vt_inc, 5, 6, 1, 2);
    attrLayout->addWidget(st_vt_range, 6, 6, 1, 2);
    attrLayout->addWidget(lk_setting, 2, 8, 1, 2);
    attrLayout->addWidget(horz_inc, 3, 8, 1, 2);
    attrLayout->addWidget(horz_range, 4, 8, 1, 2);
    attrLayout->addWidget(vert_inc, 5, 8, 1, 2);
    attrLayout->addWidget(vert_range, 6, 8, 1, 2);

    QLabel* black_space = new QLabel(QString(""));
    attrLayout->addWidget(black_space, 0, 10, 7, 1);
    attrLayout->setColumnMinimumWidth(11, 100);
}

