/*
 * Copyright ©2009  Simon Arlott
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License (Version 2) as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

enum conn_status {
	NOT_CONNECTED,
	CONNECTING,
	CONNECTED
};

struct tray_status {
	enum conn_status conn;
	char error[512];
	double temperature_celsius;
	double relative_humidity;
	double dew_point;
};

void tray_add(HWND hwnd);
void tray_update(HWND hwnd, struct tray_status *status);
void tray_remove(void);
