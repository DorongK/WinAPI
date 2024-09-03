#pragma once

class IRender// 생각해보니 인터페이스까지는 필요 없을듯?
{
public:
	virtual void Render() = 0;
};