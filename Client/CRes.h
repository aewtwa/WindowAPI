#pragma once

class CRes
{
private:
	wstring m_strKey;			// 리소스 키
	wstring m_strRelativePath;	// 리소스 상대경로

public:
	CRes();
	virtual ~CRes();

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

	void SetKey(const wstring& _strKey) { m_strKey = m_strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }
};