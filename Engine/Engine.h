#pragma once

class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:
	// �׷��� ȭ�� ũ�� ����
	WindowInfo     window;
	D3D12_VIEWPORT viewport = {};
	D3D12_RECT     scissorRect = {};

	shared_ptr<class Device> device;
	shared_ptr<class CommandQueue> cmdQueue;
	shared_ptr<class SwapChain> swapChain;
	shared_ptr<class DescriptorHeap> descHeap;
};

