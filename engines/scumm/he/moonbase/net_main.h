/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef SCUMM_HE_MOONBASE_NET_MAIN_H
#define SCUMM_HE_MOONBASE_NET_MAIN_H

namespace Scumm {

class ScummEngine_v100he;

class Net {
public:
	Net(ScummEngine_v100he *vm);
	~Net();

	int hostGame(char *sessionName, char *userName);
	int joinGame(char *IP, char *userName);
	int addUser(char *shortName, char *longName);
	int removeUser();
	int whoSentThis();
	int whoAmI();
	int createSession(char *name);
	int joinSession(int sessionIndex);
	int endSession();
	void disableSessionJoining();
	void enableSessionJoining();
	void setBotsCount(int botsCount);
	int32 setProviderByName(int32 parameter1, int32 parameter2);
	void setFakeLatency(int time);
	bool destroyPlayer(int32 playerDPID);
	int32 startQuerySessions();
	int32 updateQuerySessions();
	void stopQuerySessions();
	int querySessions();
	int queryProviders();
	int setProvider(int providerIndex);
	int closeProvider();
	bool initAll();
	bool initProvider();
	bool initSession();
	bool initUser();
	void remoteStartScript(int typeOfSend, int sendTypeParam, int priority, int argsCount, int32 *args);
	int remoteSendData(int typeOfSend, int sendTypeParam, int type, byte *data, int len, int defaultRes);
	void remoteSendArray(int typeOfSend, int sendTypeParam, int priority, int arrayIndex);
	int remoteStartScriptFunction(int typeOfSend, int sendTypeParam, int priority, int defaultReturnValue, int argsCount, int32 *args);
	void doNetworkOnceAFrame(int msecs);
	void unpackageArray(int arrayId, byte *data, int len);

private:
	int getMessageCount();
	void remoteReceiveData();

public:
	//getters
	bool getHostName(char *hostname, int length);
	bool getIPfromName(char *ip, int ipLength, char *nameBuffer);
	void getSessionName(int sessionNumber, char *buffer, int length);
	int getSessionPlayerCount(int sessionNumber);
	void getProviderName(int providerIndex, char *buffer, int length);

private:
	//mostly getters

public:
	//fields
	int _latencyTime; // ms
	bool _fakeLatency;

	ScummEngine_v100he *_vm;

	byte *_packbuffer;
	byte *_tmpbuffer;

	int _myUserId;
};

} // End of namespace Scumm

#endif
