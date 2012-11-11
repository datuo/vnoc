
#include "MsgDef.h"

#include <cstring>

//CMessageParser


using namespace std;


//RVC(获取验证码请求)
const byte* MSG_RVC::GetMachineAddress() const
{
	return CMessage::GetParam(0);
}

void MSG_RVC::SetMachineAddress(const byte* in_byte_ptr, size_t len )
{
	SetParam(0,in_byte_ptr,len);
}

//AVC(获取验证码响应)
uint MSG_AVC::GetLoginTag() const
{
	return byteToInt(CMessage::GetParam(0),1);
}

uint MSG_AVC::GetCaptchaType() const
{
	return byteToInt(CMessage::GetParam(1),1);
}

const byte* MSG_AVC::GetCaptcha() const
{
	return CMessage::GetParam(2);
}


void MSG_AVC::SetLoginTag(byte in_byte)
{
	//只占一个字节
	SetParam(0,in_byte);
}

void MSG_AVC::SetCaptchaType(byte in_byte)
{
	//只占一个字节
	SetParam(1,in_byte);
}

void MSG_AVC::SetCaptcha(const byte* in_byte_ptr,size_t len)
{
	SetParam(2,in_byte_ptr,len);
}

//RLI(登录请求)
const byte* MSG_RLI::GetVerificationCode() const
{
	return CMessage::GetParam(0);
}


const byte* MSG_RLI::GetAccountNumber() const
{
	return CMessage::GetParam(1);
}


const byte* MSG_RLI::GetPassword() const
{
	return CMessage::GetParam(2);
}

void MSG_RLI::SetVerificationCode(const byte* in_byte_ptr,size_t len )
{
	SetParam(0,in_byte_ptr,len);
}

void MSG_RLI::SetAccountNumber(const byte* in_byte_ptr,size_t len )
{
	SetParam(1,in_byte_ptr,len);
}

void MSG_RLI::SetPassword(const byte* in_byte_ptr,size_t len )
{
	SetParam(2,in_byte_ptr,len);
}

//ALI(登录应答)
uint MSG_ALI::GetLoginResult() const
{
	return byteToInt(CMessage::GetParam(0),1);
}


uint MSG_ALI::GetToken() const
{
	return byteToInt(CMessage::GetParam(1),4);
}


const byte* MSG_ALI::GetATLGUID() const
{
	return CMessage::GetParam(2);
}

void MSG_ALI::SetLoginResult( byte in_byte )
{
	SetParam(0,in_byte);
}

void MSG_ALI::SetToken(const byte* in_byte_ptr, size_t len /*= 4*/)
{
	SetParam(1,in_byte_ptr,len);
}

void MSG_ALI::SetATLGUID(const byte* in_byte_ptr, size_t len /*= 16*/ )
{
	SetParam(2,in_byte_ptr,len);
}



//RPS(个人信息同步通知)
uint MSG_RPS::GetRank() const
{
	return byteToInt(CMessage::GetParam(0),1);
}

const byte* MSG_RPS::GetNickname() const
{ 
	return CMessage::GetParam(1);
}

const byte* MSG_RPS::GetAutograph() const
{
	return CMessage::GetParam(2);
}

uint MSG_RPS::GetHeadForm() const
{
	return byteToInt(CMessage::GetParam(3),1);
}

const byte* MSG_RPS::GetHeadPortrait() const
{
	return CMessage::GetParam(4);
}

void MSG_RPS::SetRank( byte in_byte )
{
	SetParam(0,in_byte);
}


void MSG_RPS::SetNickname(const byte* in_byte_ptr,size_t len )
{
	SetParam(1,in_byte_ptr,len);
}


void MSG_RPS::SetAutograph(const byte* in_byte_ptr,size_t len )
{
	SetParam(2,in_byte_ptr,len);
}

void MSG_RPS::SetHeadForm( byte in_byte )
{
	SetParam(3,in_byte);
}

void MSG_RPS::SetHeadPortrait(const byte* in_byte_ptr,size_t len )
{
	SetParam(4,in_byte_ptr,len);
}




//APS(个人信息同步通知确认)
const byte* MSG_APS::GetMessageSynchro() const
{
	return CMessage::GetParam(0);
}

void MSG_APS::SetMessageSynchro(const byte* in_byte_ptr,size_t len )
{
	SetParam(0,in_byte_ptr,len);
}

//MSG_RCI
uint MSG_RCI::GetRoomID() const
{
	return byteToInt(CMessage::GetParam(0),4);
}

void MSG_RCI::SetRoomID( uint in_int )
{
	SetParam(0,in_int);
}


//MSG_ACI
uint MSG_ACI::GetRoomID() const
{
	return byteToInt(CMessage::GetParam(0),4);
}

uint MSG_ACI::GetRoomType() const
{
	return byteToInt(CMessage::GetParam(1),4);
}

const byte* MSG_ACI::GetRoomName() const
{
	return CMessage::GetParam(2);
}

uint MSG_ACI::GetRoomRank() const
{
	return byteToInt(CMessage::GetParam(3),4);
}

uint MSG_ACI::GetRoomState() const
{
	return byteToInt(CMessage::GetParam(4),4);
}

const byte* MSG_ACI::GetRoomPassword() const
{
	return CMessage::GetParam(5);
}

uint MSG_ACI::GetRoomPeopleNumMax() const
{
	return byteToInt(CMessage::GetParam(6),4);
}

uint MSG_ACI::GetRoomPeopleNum() const
{
	return byteToInt(CMessage::GetParam(7),4);
}

int MSG_ACI::GetRoomPeopleList( std::vector<int>& PeopleList ) const
{
	return GetParam<int>(8,PeopleList);
}

uint MSG_ACI::GetRoomManageID() const
{
	return byteToInt(CMessage::GetParam(9),4);
}

void MSG_ACI::SetRoomID( uint in_int )
{
	SetParam(0,in_int);
}

void MSG_ACI::SetRoomType( uint in_int )
{
	SetParam(1,in_int);
}

void MSG_ACI::SetRoomName( const byte* in_byte_ptr,size_t len )
{
	SetParam(2,in_byte_ptr,len);
}

void MSG_ACI::SetRoomRank( uint in_int )
{
	SetParam(3,in_int);
}

void MSG_ACI::SetRoomState( uint in_int )
{
	SetParam(4,in_int);
}

void MSG_ACI::SetRoomPassword( const byte* in_byte_ptr,size_t len )
{
	SetParam(5,in_byte_ptr,len);
}

void MSG_ACI::SetRoomPeopleNumMax( uint in_int )
{
	SetParam(6,in_int);
}

void MSG_ACI::SetRoomPeopleNum( uint in_int )
{
	SetParam(7,in_int);
}

void MSG_ACI::SetRoomPeopleList( std::vector<int> PeopleList )
{
	SetParam<int>(8,PeopleList);
}

void MSG_ACI::SetRoomManageID( uint in_int )
{
	SetParam(9,in_int);	
}