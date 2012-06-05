
#include "PackMessage.h"

#include <cstring>

using namespace std;

int PackMessage::_Head(const CMessage* const msg_clss,byte* buf, size_t len)
{
	//head---------------------
	int index = 0;
	int tmpInt = 0;
	byte tmpByte[4] = {0};
	if (buf == NULL)
	{
		return -2;
	}

	// 	if (len < rvc->GetDataLen())
	// 	{
	// 		return -1;
	// 	}
	//����ͷβ���  �Զ����
	// 	if ((avc->GetBeginTab() != true ) && (avc->GetEndTab() != true))
	// 	{
	// 		return -1;
	// 	}

	buf[0] = MSG_BEGIN;
	index++;

	CHECKUP_DATALEN(index,len);
	buf[index] = msg_clss->GetVersion();
	index++;
	CHECKUP_DATALEN(index,len);
	memset(tmpByte,0,4);
	IntTobyte(msg_clss->GetSerial(),tmpByte);
	//��Ϊ���ֻ��2λ ����ֻȡ��λ
	CHECKUP_DATALEN(index,len);
	for (int i = 2; i < 4; i++,index++)
	{
		buf[index] = tmpByte[ i ];
	}


	memset(tmpByte,0,4);
	IntTobyte(msg_clss->GetDataLen(),tmpByte);
	CHECKUP_DATALEN(index,len);
	for (int record = 0; record < 4; index++,record++ )
	{
		buf[index] = tmpByte[record];
	}
	//GUID
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < 16; index++, i++)
	{
		buf[index] = msg_clss->GetGUID()[i];
	}
	//ָ��
	CHECKUP_DATALEN(index,len);
	buf[index] = msg_clss->GetCommand();
	index++;
	//����λ��
	CHECKUP_DATALEN(index,len);
	memset(tmpByte,0,4);
	IntTobyte(msg_clss->GetObligate(),tmpByte);
	for (int i = 0; i < 4; index++ , i++)
	{
		buf[index] = tmpByte[ i ];
	}
	//��������
	CHECKUP_DATALEN(index,len);
	buf[index]  = msg_clss->GetCmlCount();
	index++;
	return index;
}

int PackMessage::_Tail(const CMessage* const msg_clss,byte* buf,int index,size_t len)
{
	byte tmpByte[4] = {0};
	//Tail
	//Ч����
	CHECKUP_DATALEN(index,len);
	if ((msg_clss == NULL) || (buf == NULL))
	{
		return -1;
	}
	memset(tmpByte,0,4);
	IntTobyte(msg_clss->GetVerify(),tmpByte);
	//��ΪЧ����Ԥ��2λ ����ֻȡ��λ
	CHECKUP_DATALEN(index,len);
	for (int i = 2; i < 4; i++,index++)
	{
		buf[index] = tmpByte[ i ];
	}
	//��β��
	CHECKUP_DATALEN(index,len);
	buf[index] = MSG_END;
	return index;
}

int PackMessage::Pack(const MSG_RVC* const rvc,byte* buf, size_t len)
{

	byte tmpByte[4] = {0};

	int index = _Head(rvc,buf,len);
	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(rvc->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = rvc->GetCmlListLen()[i];
	}
	//����
	//1
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rvc->GetMachineAddressLen(); i++, index++)
	{
		buf[index] = rvc->GetCmlCommandList()[0][i];
	}

	//Tail
	return _Tail(rvc,buf,index,len);
}


int PackMessage::Pack(const MSG_AVC* const avc, byte* buf, size_t len)
{
	byte tmpByte[4] = {0};

	int index = _Head(avc,buf,len);
	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(avc->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = avc->GetCmlListLen()[i];
	}
	//��������
	//1
	CHECKUP_DATALEN(index,len);
	buf[index] = avc->GetCmlCommandList()[2][0];
	index++;
	//2
	CHECKUP_DATALEN(index,len);
	buf[index] = avc->GetCmlCommandList()[1][0];
	index++;
	//3
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < avc->GetCaptchaLen(); i++, index++)
	{
		buf[index] = avc->GetCmlCommandList()[0][i];
	}
	//Tail
	return _Tail(avc,buf,index,len);
}


int PackMessage::Pack(const MSG_RLI* const rli,byte* buf, size_t len)
{
	byte tmpByte[4] = {0};

	int index = _Head(rli,buf,len);

	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(rli->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = rli->GetCmlListLen()[i];
	}

	//��������
	//1
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rli->GetVerificationCodeLen(); i++, index++)
	{
		buf[index] = rli->GetCmlCommandList()[2][i];
	}
	//2
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rli->GetAccountNumberLen(); i++, index++)
	{
		buf[index] = rli->GetCmlCommandList()[1][i];
	}
	//3
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rli->GetPasswordLen(); i++, index++)
	{
		buf[index] = rli->GetCmlCommandList()[0][i];
	}

	//Tail
	return _Tail(rli,buf,index,len);
}

int PackMessage::Pack(const MSG_ALI* const ali,byte* buf, size_t len)
{
	byte tmpByte[4] = {0};

	int index = _Head(ali,buf,len);

	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(ali->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = ali->GetCmlListLen()[i];
	}
	//��������
	//1
	CHECKUP_DATALEN(index,len);
	buf[index] = ali->GetCmlCommandList()[2][0];
	index++;
	//2
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < ali->GetTokenLen(); i++, index++)
	{
		buf[index] = ali->GetCmlCommandList()[1][i];
	}
	//3
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < ali->GetTokenLen(); i++, index++)
	{
		buf[index] = ali->GetCmlCommandList()[0][i];
	}

	//Tail
	return _Tail(ali,buf,index,len);

}


int PackMessage::Pack(const MSG_RPS* const rps,byte* buf, size_t len)
{
	byte tmpByte[4] = {0};

	int index = _Head(rps,buf,len);


	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(rps->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = rps->GetCmlListLen()[i];
	}
	//��������
	//1
	CHECKUP_DATALEN(index,len);
	buf[index] = rps->GetCmlCommandList()[4][0];
	index++;
	//2
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rps->GetNicknameLen(); i++, index++)
	{
		buf[index] = rps->GetCmlCommandList()[3][i];
	}
	//3
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rps->GetAutographLen(); i++, index++)
	{
		buf[index] = rps->GetCmlCommandList()[2][i];
	}
	//4
	CHECKUP_DATALEN(index,len);
	buf[index] = rps->GetCmlCommandList()[1][0];
	index++;
	//5
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < rps->GetHeadPortraitLen(); i++, index++)
	{
		buf[index] = rps->GetCmlCommandList()[0][i];
	}

	//Tail
	return _Tail(rps,buf,index,len);

}


int PackMessage::Pack(const MSG_APS* const aps,byte* buf, size_t len)
{
	byte tmpByte[4] = {0};

	int index = _Head(aps,buf,len);
	//body
	//��������
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < (int)(aps->GetCmlCount() * 4); i++, index++)
	{
		buf[index] = aps->GetCmlListLen()[i];
	}
	//��������
	//1
	CHECKUP_DATALEN(index,len);
	for (int i = 0; i < aps->GetMessageSynchroLen(); i++, index++)
	{
		buf[index] = aps->GetCmlCommandList()[0][i];
	}

	//Tail
	return _Tail(aps,buf,index,len);
}

//GetMessageLen

// int PackMessage::GetMessageLen( MSG_AVC* avc )
// {
// 	int Head = 30;
// 	int Tail = 3;
// 	int Param;
// 	int PLen;
// 	PLen = avc->GetCmlCount() * 4;
// 	Param = avc->GetCaptchaLen() + 1 + 1;
// 	return Param + PLen + Head + Tail;
// }

int PackMessage::GetMessageLen(const CMessage* const msg)
{
	int Head = 30;
	int Tail = 3;
	int Param = 0;
	int PLen  = 0;

	MSG_AVC* avc;
	MSG_RVC* rvc;
	MSG_ALI* ali;
	MSG_RLI* rli;
	MSG_RPS* rps;
	MSG_APS* aps;

	if (!msg)
	{
		return 0;
	}


	PLen  =  msg->GetCmlCount() * 4;
	
	switch (msg->GetMessageType())
	{
	case MSG_AVC_TYPE:
		avc = (MSG_AVC*)msg;
		Param = avc->GetCaptchaLen() + 1 + 1;
		break;
	case MSG_RVC_TYPE:
		rvc = (MSG_RVC*)msg;
		Param = rvc->GetMachineAddressLen();
		break;
	case MSG_ALI_TYPE:
		ali = (MSG_ALI*)msg;
		Param = ali->GetATLGUIDLen() + ali->GetTokenLen() + 1;
		break;
	case MSG_RLI_TYPE:
		rli = (MSG_RLI*)msg;
		Param = rli->GetAccountNumberLen() + rli->GetPasswordLen() + rli->GetVerificationCodeLen();
		break;
	case MSG_RPS_TYPE:
		rps = (MSG_RPS*)msg;
		Param = rps->GetNicknameLen() + rps->GetAutographLen() + rps->GetHeadPortraitLen() + 1 + 1;
		break;
	case MSG_APS_TYPE:
		aps = (MSG_APS*)msg;
		Param = aps->GetMessageSynchroLen();
		break;
	}
	return Param + PLen + Head + Tail;
}