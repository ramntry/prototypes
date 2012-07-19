#include <QtGui/QHBoxLayout>

#include "filePathSelector.h"

using namespace pluginManager;

FilePathSelector::FilePathSelector(QWidget *parent)
		: QFrame(parent)
		, mFilePathEdit(new QLineEdit)
		, mBrowseButton(new QPushButton(tr("&Browse")))
{
	mFilePathEdit->setReadOnly(true);
	mBrowseButton->setDisabled(true);
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(mFilePathEdit);
	layout->addWidget(mBrowseButton);
	setLayout(layout);
}

void FilePathSelector::setFilePath(const QString &filePath)
{
	mFilePathEdit->setText(filePath);
}
