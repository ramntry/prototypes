#pragma once
#include <QtGui/QWidget>
#include <QtCore/QHash>

#include "treeWidget.h"
#include "filePathSelector.h"

namespace pluginManager {

class Configurator : public QWidget
{
	Q_OBJECT

public:
	Configurator(QWidget *parent = 0, QHash<QString, QStringList> const &settings = QHash<QString, QStringList>());
	void setInitialValues(QStringList const &pluginIdStrings, QStringList const &metamodelIdStrings);

public slots:
	void suggestToAddPlugin();
	void suggestToAddMetamodel();
	void deleteSelected();

public slots:
	void setFilePathInSelector(QTreeWidgetItem *item);

private:
	static QSize const mMinimumSize;

	TreeWidget *mTreeWidget;
	FilePathSelector *mFilePathSelector;
};

}
