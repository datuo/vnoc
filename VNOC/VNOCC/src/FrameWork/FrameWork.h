#pragma once
#include "IFrameWork.h"
#include <atlsync.h>
#include <map>

typedef std::map<FrameModule,IModule*>	ModuleMap;

class CFrameWork : public IFrameWork
{
public:
	CFrameWork();
	~CFrameWork();
public:
	STDMETHOD( Initialize(IModule* UpperFrame=NULL) );
	STDMETHOD( UnInitialize() );
	STDMETHOD( Run() );
	STDMETHOD( Terminate() );
	STDMETHOD( RegisterModule	(IModule* iModule,FrameModule module) );
	STDMETHOD( GetModule		(IModule** piModule,FrameModule module) );
	STDMETHOD( RemoveModule		(IModule* iModule) );
	STDMETHOD( SetStartupModule	(FrameModule module) );
private:
	IModule* _FindModule(FrameModule module);
private:
	FrameModule m_startupModule;
	ModuleMap m_map;
	ATL::CCriticalSection m_cs;
};