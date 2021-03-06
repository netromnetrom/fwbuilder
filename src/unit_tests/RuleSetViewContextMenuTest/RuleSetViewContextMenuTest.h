/*

                          Firewall Builder

                 Copyright (C) 2010 NetCitadel, LLC

  Author:  Roman Bovsunivskiy     a2k0001@gmail.com

  $Id: RuleSetViewContextMenuTest.h 2786 2010-04-01 14:05:36Z a2k $

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef INSTDIALOGTEST_H
#define INSTDIALOGTEST_H

#include <QTest>
#include <QTreeWidget>

#include "newClusterDialog.h"
#include "upgradePredicate.h"
#include "FWBTree.h"
#include "fwbuilder/Library.h"
#include "instDialog.h"
#include "FWWindow.h"
#include "ObjectTreeView.h"
#include "ObjectTreeViewItem.h"
#include "RuleSetView.h"
#include "events.h"

#include "fwbuilder/Firewall.h"
#include "fwbuilder/Policy.h"

class RuleSetViewContextMenuTest : public QObject
{
    Q_OBJECT
    bool failed;
    ObjectManipulator *om;
    RuleSetView *view;
    const char *ssh_auth_sock;
    void openPolicy(QString fw);
    libfwbuilder::Library* findUserLibrary();
    QString groupToCreate;
    QString itemToClick;
    bool clicked;
    void clickMenuItem(QString item);
    QPoint findRulePosition(int rule);
    QPoint findRulePosition(libfwbuilder::Rule *rule);
    QPoint getViewBottomPoint();
    QPoint findCell(libfwbuilder::Rule *rule, int col);
    void createGroup(QString name);
    void verifyMenu(int column);
    QStringList names;
    libfwbuilder::Firewall *firewall;

private slots:
    void initTestCase();
    void test_menus();
    void test_group_menus();
    void test_platforms();

public slots:
    void actuallyClickMenuItem();
    void actuallyCreateGroup();

    void actuallyVerifyMenu();
};

#endif // INSTDIALOGTEST_H
