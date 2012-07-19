#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>

#include "configurator.h"
#include "../../tools/notImplementedYetQMessageBox.h"

using namespace pluginManager;

QSize const Configurator::mMinimumSize = QSize(600, 300);

Configurator::Configurator(QWidget *parent, const QHash<QString, QStringList> &settings)
		: QWidget(parent)
		, mTreeWidget(new TreeWidget)
		, mFilePathSelector(new FilePathSelector)
{
	setInitialValues(settings["Plugins"], settings["Metamodels"]);

	mTreeWidget->header()->setResizeMode(QHeaderView::ResizeToContents);
	setMinimumSize(mMinimumSize);

	QVBoxLayout *viewLayout = new QVBoxLayout;
	viewLayout->addWidget(mTreeWidget);
	viewLayout->addWidget(mFilePathSelector);

	QPushButton *addPluginButton = new QPushButton(tr("Add &plugin"));
	QPushButton *addMetamodelButton = new QPushButton(tr("Add &metamodel"));
	QPushButton *deleteButton = new QPushButton(tr("&Delete"));

	QVBoxLayout *buttonsLayout = new QVBoxLayout;
	buttonsLayout->addWidget(addPluginButton);
	buttonsLayout->addWidget(addMetamodelButton);
	buttonsLayout->addWidget(deleteButton);
	buttonsLayout->addStretch(-1);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(viewLayout);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	connect(mTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), SLOT(setFilePathInSelector(QTreeWidgetItem *)));
	connect(addPluginButton, SIGNAL(clicked()), this, SLOT(suggestToAddPlugin()));
	connect(addMetamodelButton, SIGNAL(clicked()), this, SLOT(suggestToAddMetamodel()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelected()));
}

void Configurator::setInitialValues(const QStringList &pluginIdStrings, const QStringList &metamodelIdStrings)
{
	foreach (QString const &pluginIdString, pluginIdStrings) {
		mTreeWidget->addPluginItem(pluginIdString);
	}
	foreach (QString const &metamodelIdString, metamodelIdStrings) {
		mTreeWidget->addMetamodelItem(metamodelIdString);
	}
}

void Configurator::suggestToAddPlugin()
{
	showNotImplementedYetMessage("<b>This opens the dialog prompts you to select the plugin file. If the plugin"
			" is successfully connect, then it appears in the list of plugins</b>");
}

void Configurator::suggestToAddMetamodel()
{
	showNotImplementedYetMessage("<b>Likewise about plugin</b>");
}

void Configurator::deleteSelected()
{
	showNotImplementedYetMessage();
}

void Configurator::setFilePathInSelector(QTreeWidgetItem *item)
{
	mFilePathSelector->setFilePath(item->data(0, Qt::UserRole).toString());
}
