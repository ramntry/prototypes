#include <QApplication>

#include "configurator.h"

using namespace pluginManager;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QHash<QString, QStringList> settings;

	QStringList plugins;
	plugins << "~/projects/qreal/ramn_fork/qreal/bin/plugins/libblockDiagramEditor.so"
			";true;BlockDiagram;Block diagram editor"
			<< "~/projects/qreal/ramn_fork/qreal/bin/plugins/libmetaEditor.so"
			";false;MetaEditor;Meta editor";
	settings["Plugins"] = plugins;

	Configurator w(NULL, settings);
	w.show();

	return a.exec();
}
