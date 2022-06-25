#pragma once

/*
	审核状态文件
*/
enum class Status
{
	IN_REVIEW,	// 审核中
	PASS,	// 通过
	FAIL,	// 未通过
	CANCEL,	// 取消
};
