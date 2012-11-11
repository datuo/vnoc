


#pragma  once

#include "BaseMessage.h"

//RVC(获取验证码请求)
class MSG_RVC: public CMessage
{
public:
	
	MSG_RVC(){
		//0x14
		CMessage::InitiaPack(20,1);
	}
	virtual ~MSG_RVC(){}

public:
	//机器地址
	const byte* GetMachineAddress() const;

	void SetMachineAddress(const byte* in_byte_ptr, size_t len);

	int  GetMachineAddressLen()const{
		return  CMessage::GetParamLen(0);
    }
};

//AVC(获取验证码响应)
class MSG_AVC: public CMessage
{
public:

	MSG_AVC(){
		//0x15
		CMessage::InitiaPack(21,3);
	}

	virtual ~MSG_AVC(){}

public:
	//获取验证码结果：1字节，用来标志此次登录的结果
    uint GetLoginTag() const;
	//验证码类型：标志后面的验证码是用的何种载体，（根据验证码载体的类型定义一个枚举）
	uint GetCaptchaType() const;
	//验证码载体：由验证码载体长度参数指定大小，可以是任意格式图像或者声音。
	const byte* GetCaptcha() const;
	

	void SetLoginTag(byte in_byte);

	void SetCaptchaType(byte in_byte);

	void SetCaptcha(const byte* in_byte_ptr,size_t len);


	//
    int GetCaptchaLen() const {
		return CMessage::GetParamLen(2);
	}

};


//RLI(登录请求)
class MSG_RLI:public CMessage
{

public:

	MSG_RLI(){
		//0x16
		CMessage::InitiaPack(22,3);
	}
	virtual ~MSG_RLI(){}

public:
	//验证码：未知长度，为AUT传回来的图片包含的字符组成，此参数在服务器端应该与令牌绑定（有一个验证码-令牌映射）
	const byte* GetVerificationCode() const;
	//用户帐号：用户帐号编码的二进制数据
	const byte* GetAccountNumber() const;
	//用户密码：密码经过处理后的二进制数据
	const byte* GetPassword() const;


	void SetVerificationCode(const byte* in_byte_ptr,size_t len);

	void SetAccountNumber(const byte* in_byte_ptr,size_t len);

	void SetPassword(const byte* in_byte_ptr,size_t len);


	int GetVerificationCodeLen() const{
		return CMessage::GetParamLen(0);
	}

	int GetAccountNumberLen() const{
		return CMessage::GetParamLen(1);
	}

	int GetPasswordLen() const{
		return CMessage::GetParamLen(2);
	}
};


//ALI(登录应答)
class MSG_ALI:public CMessage
{

public:

	MSG_ALI(){
		//0x17
		CMessage::InitiaPack(23,3);
	}

	virtual ~MSG_ALI(){}

public:
	//登录结果：1字节，用来标志此次登录的结果
	uint GetLoginResult() const;
	//令牌长度：4字节，0x00 00 00 10用户帐号编码后的长度，单位为字节
	uint GetToken() const;
	//令牌：16字节，一个GUID ，帐号验证通过后生成，通过此数据包发给客户端，之后的指令在包头部均需带上此令牌
	const byte* GetATLGUID() const;

	void SetLoginResult(byte in_byte);

	void SetToken(const byte* in_byte_ptr,size_t len = 4);

	void SetATLGUID(const byte* in_byte_ptr, size_t len = 16);


	int GetATLGUIDLen() const{
		return CMessage::GetParamLen(1);
	}

	int GetTokenLen() const{
		return CMessage::GetParamLen(2);
	}
};


//RPS(个人信息同步通知)
class MSG_RPS:public CMessage
{

public:

	MSG_RPS(){
		//0x18
		CMessage::InitiaPack(24,5);
	}
		
	virtual ~MSG_RPS(){}

public:
	//用户权限
	uint GetRank() const;
	//昵称
	const byte* GetNickname() const;
	//个人签名
	const byte* GetAutograph() const;
	//头像格式
	uint GetHeadForm() const;
	//头像
	const byte* GetHeadPortrait() const;

	void SetRank(byte in_byte);

	void SetNickname(const byte* in_byte_ptr,size_t len);

	void SetAutograph(const byte* in_byte_ptr,size_t len);

	void SetHeadForm(byte in_byte);

	void SetHeadPortrait(const byte* in_byte_ptr,size_t len);


	int GetNicknameLen() const{
		return CMessage::GetParamLen(1);
	}

	int GetAutographLen() const{
		return CMessage::GetParamLen(2);
	}

	int GetHeadPortraitLen() const{
		return CMessage::GetParamLen(4);
	}
};


//APS(个人信息同步通知确认)
class MSG_APS:public CMessage
{

public:

	MSG_APS(){
		//0x19
		CMessage::InitiaPack(25,1);
	}

	virtual ~MSG_APS(){}

public:
	//个人信息同步通知
	const byte* GetMessageSynchro() const;

	void SetMessageSynchro(const byte* in_byte_ptr,size_t len);

	int GetMessageSynchroLen() const{
		return CMessage::GetParamLen(0);
	}

};


class MSG_RCL:public CMessage
{
public:
	MSG_RCL(){
		//0x1E
		CMessage::InitiaPack(30,10);
	}

	//保留
	//uint GetUserType() const;

	//void SetUserType(uint in_int);

	virtual ~MSG_RCL(){}
};



class MSG_ACL:public CMessage
{
public:
	MSG_ACL(){
		//0x1F
		CMessage::InitiaPack(31,1);
	}
	virtual ~MSG_ACL(){}

public:

};

class MSG_RCI: public CMessage
{
public:

	MSG_RCI(){
		//0x20
		CMessage::InitiaPack(32,1);
	}

	virtual ~MSG_RCI(){}

public:
	//获取房间ID：要获取信息的房间的ID
	uint GetRoomID() const;

	void SetRoomID(uint in_int);
};


class MSG_ACI: public CMessage
{
public:

	MSG_ACI(){
		//0x21
		CMessage::InitiaPack(33,10);
	}

	virtual ~MSG_ACI(){}

public:

	//获取房间ID：要获取信息的房间的ID
	uint GetRoomID() const;

	uint GetRoomType() const;

	const byte* GetRoomName() const;

	uint GetRoomRank() const;

	uint GetRoomState() const;

	const byte* GetRoomPassword() const;

	uint GetRoomPeopleNumMax()  const;

	uint GetRoomPeopleNum()   const;

	int  GetRoomPeopleList(std::vector<int>& PeopleList) const;

	uint GetRoomManageID()    const;


	void SetRoomID(uint in_int);

	void SetRoomType(uint in_int);

	void SetRoomName(const byte* in_byte_ptr,size_t len);

	void SetRoomRank(uint in_int);

	void SetRoomState(uint in_int);

	void SetRoomPassword(const byte* in_byte_ptr,size_t len);

	void SetRoomPeopleNumMax(uint in_int);

	void SetRoomPeopleNum(uint in_int);

	void  SetRoomPeopleList(std::vector<int> PeopleList);

	void SetRoomManageID(uint in_int);

	int GetRoomNameLen() const{
		return CMessage::GetParamLen(2);
	}

	int GetRoomPasswordLen() const{
		return CMessage::GetParamLen(5);
	}

	int GetPeopleListSize() const{
		return (CMessage::GetParamLen(8) / 4);
	}
};