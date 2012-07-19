#pragma once
#include <QtGui/QTreeWidget>

namespace pluginManager {

enum ItemIdStringComponent
{
	filePath = 0
	, isActive
	, name
	, description
};

class TreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	explicit TreeWidget(QWidget *parent = 0);

	void addPluginItem(const QString &itemIdString);
	void addMetamodelItem(const QString &itemIdString);

private:
	void addItem(QTreeWidgetItem *parent, const QString &itemIdString);

	QTreeWidgetItem *mPlugins;
	QTreeWidgetItem *mMetamodels;
};

}
