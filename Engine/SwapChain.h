#pragma once

// ��ȯ �罽
// - ���� ���� ���� �ִ� ��Ȳ�� ����
// - � �������� ��� ������� ������
// - GPU�� ������ ��� (����)
// - ����� �޾Ƽ� ȭ�鿡 �׷��ش�

// - � ����(Buffer)�� �׷��� �ǳ��޶�� ��Ź�غ���
// - Ư�� ���̸� ���� -> ó���� �ǳ��ְ� -> ������� �ش� ���̿� �޴´� OK
// - �츮 ȭ�鿡 Ư�� ���̸� ������ش�

// - �׷��� ȭ�鿡 ���� ����� ����ϴ� ���߿�, ���� ȭ�鵵 ���ָ� �ðܾ� ��
// - ���� ȭ�� ������� �̹� ȭ�� ��¿� �����
// - Ư�� ���̸� 2�� ����, �ϳ��� ���� ȭ���� �׷��ְ�, �ϳ��� ���� �ñ��...
// - Double Buffering!

// - [0] [1]
// ���� ȭ�� [1]  <-> GPU �۾��� [1] BackBuffer

class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return renderTargets[index]; }

	uint32 GetCurrentBackBufferIndex() { return backBufferIndex; }
	ComPtr<ID3D12Resource> GetCurrentBackBufferResource() { return renderTargets[backBufferIndex]; }

private:
	ComPtr<IDXGISwapChain>	swapChain;
	ComPtr<ID3D12Resource>	renderTargets[SWAP_CHAIN_BUFFER_COUNT];
	uint32					backBufferIndex = 0;
};