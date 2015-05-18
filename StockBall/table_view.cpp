#include "table_view.h"
#include "QPainter"
#include "QPalette"
#include "QStandardItemModel"
#include "QHeaderView"
#include "qabstractscrollarea.h"
#include "qfile.h"
#include "QScrollBar"

TableView::TableView(QWidget *parent /*= 0*/) : QTableView(parent)
{
	setMinimumSize(270, 560);
	setFrameShape(QFrame::NoFrame);
	init();

	QFile qss(":/qss/default");
	qss.open(QFile::ReadOnly);
	verticalScrollBar()->setStyleSheet(qss.readAll());
	qss.close();
}

void TableView::paintEvent(QPaintEvent *e)
{
	QTableView::paintEvent(e);
}

TableView::~TableView()
{

}

void TableView::init()
{
	QStandardItemModel *student_model = new QStandardItemModel();
	student_model->setColumnCount(4);    // 设置列数
	student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
	student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Value")));
	student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Change")));
	student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Percent")));
	//利用setModel()方法将数据模型与QTableView绑定
	setModel(student_model);
	setColumnWidth(0, 60);
	setColumnWidth(1, 70);
	setColumnWidth(2, 62);
	setColumnWidth(3, 61);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	verticalHeader()->hide();
	horizontalHeader()->hide();
	setShowGrid(false);
	setStyleSheet("border:none;");

	for (int i = 0; i < 30; ++i)
	{
		student_model->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("深圳指数")));
		student_model->setItem(i, 1, new QStandardItem(QString("14672.23")));
		student_model->setItem(i, 2, new QStandardItem(QString("-22.32")));
		student_model->setItem(i, 3, new QStandardItem(QString("+0.089")));
		setRowHeight(i, 25);

		student_model->item(i, 0)->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		student_model->item(i, 1)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		student_model->item(i, 2)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		student_model->item(i, 3)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

		//设置单元格文本颜色，张三的数据设置为红色
		student_model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 1)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 2)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 3)->setForeground(QBrush(QColor(255, 0, 0)));

	}
}

