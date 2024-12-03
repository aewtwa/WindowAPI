#pragma once

class CRes
{
private:
	wstring m_strKey;			// ���ҽ� Ű
	wstring m_strRelativePath;	// ���ҽ� �����

public:
	CRes();
	virtual ~CRes();

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

	void SetKey(const wstring& _strKey) { m_strKey = m_strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }
};