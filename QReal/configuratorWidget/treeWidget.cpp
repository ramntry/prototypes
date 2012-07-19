#include <QtGui/QHeaderView>

#include "treeWidget.h"

using namespace pluginManager;

TreeWidget::TreeWidget(QWidget *parent)
		: QTreeWidget(parent)
		, mPlugins(new QTreeWidgetItem(this))
		, mMetamodels(new QTreeWidgetItem(this))
{
	QStringList headerLabels;
	headerLabels << tr("Name") << tr("Description") << tr("State");
	setHeaderLabels(headerLabels);

	mPlugins->setText(0, tr("Plugins"));
	mMetamodels->setText(0, tr("Metamodels"));
	expandAll();
}

void TreeWidget::addPluginItem(QString const &itemIdString)
{
	addItem(mPlugins, itemIdString);
}

void TreeWidget::addMetamodelItem(QString const &itemIdString)
{
	addItem(mMetamodels, itemIdString);
}

void TreeWidget::addItem(QTreeWidgetItem *parent, QString const &itemIdString)
{
	QStringList itemComponents = itemIdString.split(";", QString::SkipEmptyParts);
	QTreeWidgetItem *item = new QTreeWidgetItem(parent);
	item->setData(0, Qt::UserRole, itemComponents.at(filePath));
	item->setCheckState(0, QVariant(itemComponents.at(isActive)).toBool() ? Qt::Checked : Qt::Unchecked);
	item->setText(0, itemComponents.at(name));
	item->setText(1, itemComponents.at(description));
	item->setIcon(2, style()->standardIcon(QStyle::SP_DialogOkButton));
}
