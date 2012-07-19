#include <QtGui/QMessageBox>

void showNotImplementedYetMessage(QString const &descriptionOfExpectedActions = "")
{
	QMessageBox message(
		QMessageBox::Critical
		, "This functionality in not implemented yet."
		, "Perhaps you're working with a demonstrational prototype and requested features which have not yet been"
				" implemented." + QString(descriptionOfExpectedActions.isEmpty() ? "" : " Instead the messages in a real"
				" application, you can expect the following: ") + descriptionOfExpectedActions
		, QMessageBox::Ok
	);
	message.exec();
}
