/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *form)
    {
        if (form->objectName().isEmpty())
            form->setObjectName(QStringLiteral("form"));
        form->resize(400, 300);
        verticalLayoutWidget = new QWidget(form);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(29, 19, 241, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 22, 91, 51));
        pushButton_2 = new QPushButton(form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 110, 91, 51));
        pushButton_3 = new QPushButton(form);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(294, 200, 81, 51));

        retranslateUi(form);

        QMetaObject::connectSlotsByName(form);
    } // setupUi

    void retranslateUi(QWidget *form)
    {
        form->setWindowTitle(QApplication::translate("form", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("form", "\347\247\215\347\261\273\345\210\206\345\270\203", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("form", "\351\207\215\351\207\217\345\210\206\345\270\203", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("form", "\346\227\245\346\234\237\345\210\206\345\270\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class form: public Ui_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
