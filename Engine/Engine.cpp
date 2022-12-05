#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"

void Engine::Init(const WindowInfo& info)
{
	window = info;
	ResizeWindow(info.width, info.height);

	// 그려질 화면 크기를 설정
	viewport = { 0, 0, static_cast<FLOAT>(info.width), static_cast<FLOAT>(info.height), 0.0f, 1.0f };
	scissorRect = CD3DX12_RECT(0, 0, info.width, info.height);

	device = make_shared<Device>();
	cmdQueue = make_shared<CommandQueue>();
	swapChain = make_shared<SwapChain>();
	descHeap = make_shared<DescriptorHeap>();

	device->Init();
	cmdQueue->Init(device->GetDevice(), swapChain, descHeap);
	swapChain->Init(info, device->GetDXGI(), cmdQueue->GetCmdQueue());
	descHeap->Init(device->GetDevice(), swapChain);
}

void Engine::Render()
{
	RenderBegin();

	// TODO : 나머지 물체들을 그려준다

	RenderEnd();
}

void Engine::RenderBegin()
{
	cmdQueue->RenderBegin(&viewport, &scissorRect);
}

void Engine::RenderEnd()
{
	cmdQueue->RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	window.width = width;
	window.height = height;

	RECT rect = { 0, 0, width, height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(window.hwnd, 0, 100, 100, width, height, 0);
}