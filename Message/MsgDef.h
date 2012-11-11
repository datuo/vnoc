


#pragma  once

#include "BaseMessage.h"

//RVC(��ȡ��֤������)
class MSG_RVC: public CMessage
{
public:
	
	MSG_RVC(){
		//0x14
		CMessage::InitiaPack(20,1);
	}
	virtual ~MSG_RVC(){}

public:
	//������ַ
	const byte* GetMachineAddress() const;

	void SetMachineAddress(const byte* in_byte_ptr, size_t len);

	int  GetMachineAddressLen()const{
		return  CMessage::GetParamLen(0);
    }
};

//AVC(��ȡ��֤����Ӧ)
class MSG_AVC: public CMessage
{
public:

	MSG_AVC(){
		//0x15
		CMessage::InitiaPack(21,3);
	}

	virtual ~MSG_AVC(){}

public:
	//��ȡ��֤������1�ֽڣ�������־�˴ε�¼�Ľ��
    uint GetLoginTag() const;
	//��֤�����ͣ���־�������֤�����õĺ������壬��������֤����������Ͷ���һ��ö�٣�
	uint GetCaptchaType() const;
	//��֤�����壺����֤�����峤�Ȳ���ָ����С�������������ʽͼ�����������
	const byte* GetCaptcha() const;
	

	void SetLoginTag(byte in_byte);

	void SetCaptchaType(byte in_byte);

	void SetCaptcha(const byte* in_byte_ptr,size_t len);


	//
    int GetCaptchaLen() const {
		return CMessage::GetParamLen(2);
	}

};


//RLI(��¼����)
class MSG_RLI:public CMessage
{

public:

	MSG_RLI(){
		//0x16
		CMessage::InitiaPack(22,3);
	}
	virtual ~MSG_RLI(){}

public:
	//��֤�룺δ֪���ȣ�ΪAUT��������ͼƬ�������ַ���ɣ��˲����ڷ�������Ӧ�������ư󶨣���һ����֤��-����ӳ�䣩
	const byte* GetVerificationCode() const;
	//�û��ʺţ��û��ʺű���Ķ���������
	const byte* GetAccountNumber() const;
	//�û����룺���뾭�������Ķ���������
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


//ALI(��¼Ӧ��)
class MSG_ALI:public CMessage
{

public:

	MSG_ALI(){
		//0x17
		CMessage::InitiaPack(23,3);
	}

	virtual ~MSG_ALI(){}

public:
	//��¼�����1�ֽڣ�������־�˴ε�¼�Ľ��
	uint GetLoginResult() const;
	//���Ƴ��ȣ�4�ֽڣ�0x00 00 00 10�û��ʺű����ĳ��ȣ���λΪ�ֽ�
	uint GetToken() const;
	//���ƣ�16�ֽڣ�һ��GUID ���ʺ���֤ͨ�������ɣ�ͨ�������ݰ������ͻ��ˣ�֮���ָ���ڰ�ͷ��������ϴ�����
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


//RPS(������Ϣͬ��֪ͨ)
class MSG_RPS:public CMessage
{

public:

	MSG_RPS(){
		//0x18
		CMessage::InitiaPack(24,5);
	}
		
	virtual ~MSG_RPS(){}

public:
	//�û�Ȩ��
	uint GetRank() const;
	//�ǳ�
	const byte* GetNickname() const;
	//����ǩ��
	const byte* GetAutograph() const;
	//ͷ���ʽ
	uint GetHeadForm() const;
	//ͷ��
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


//APS(������Ϣͬ��֪ͨȷ��)
class MSG_APS:public CMessage
{

public:

	MSG_APS(){
		//0x19
		CMessage::InitiaPack(25,1);
	}

	virtual ~MSG_APS(){}

public:
	//������Ϣͬ��֪ͨ
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

	//����
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
	//��ȡ����ID��Ҫ��ȡ��Ϣ�ķ����ID
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

	//��ȡ����ID��Ҫ��ȡ��Ϣ�ķ����ID
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