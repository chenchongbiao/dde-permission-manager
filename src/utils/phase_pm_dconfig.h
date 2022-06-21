/*
 * Copyright (C) 2022 ~ 2023 Deepin Technology Co., Ltd.
 *
 * Author:     weizhixiang <weizhixiang@uniontech.com>
 *
 * Maintainer: weizhixiang <weizhixiang@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PHASEPMDCONFIG
#define PHASEPMDCONFIG

#include <DConfig>

#include <QObject>
#include <QString>

#include "dconfig_settings.h"
#include "../../dbus/types/permissions_info.h"

DCORE_USE_NAMESPACE
const QString pmAppId = "dde-permission-manager";
const QString appPermissionDconfJson = "org.desktopspec.permission.dconfig";

enum DConfRtnType {
    dconfInvalidFormat = -3,
    dconfValueInvalid = -2,
    dconfKeyInvalid = -1,
    dconfAllow = 0,
    dconfDeny = 1,
    dconfNullValue = 2,

    dconfMax = 3,
};

inline QString generateAppPermissionsKey(const QString &appId, const QString &permissionGroup) {
    return appId + "+" + permissionGroup;
}

// Dconfig 配置类
class PhasePMDconfig : public DconfigSettings
{
public:
    explicit PhasePMDconfig();
    ~PhasePMDconfig();

public:
    // 获取应用的权限列表
    static QStringList getPermissionList(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey);
    // 获取应用对应权限的值
    static int getPermissionValue(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey, const QString &permissionId);
    // 获取应用的权限列表以及权限的值
    static QVariantMap getPermissionMap(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey);

    // 设置应用对应权限的值
    static bool setPermissionValue(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey, const QString &permissionId, const QString &permissionValue);
    // 设置应用的权限列表以及权限的值
    static bool setPermissionInfo(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey, const PermissionsInfo &permissionsInfo);
    // 获取应用的权限列表以及权限的值
    static void setPermissionMap(const QString &appId, const QString &permissionGroup, const QString& appPermissionDconfKey, const QVariantMap& toBeWriteMap);
};

#endif // PHASEPMDCONFIG