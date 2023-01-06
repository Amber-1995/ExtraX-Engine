#pragma once
#ifndef EXTRAX_INPUT_H
#define EXTRAX_INPUT_H

#include <bitset>
#include <ExtraX/Event.h>

namespace ExtraX
{
	struct KeyCode
	{
		KeyCode() = delete;

		static constexpr int Unknown = 0x00;
		static constexpr int LeftMouseButton = 0x01;
		static constexpr int RightMouseButton = 0x02;
		static constexpr int ControlBreakProcessing = 0x03;
		static constexpr int MiddleMouseButton = 0x04;
		static constexpr int X1MouseButton = 0x05;
		static constexpr int X2MouseButton = 0x06;

		static constexpr int Backspace = 0x08;
		static constexpr int Tab = 0x09;

		static constexpr int Clear = 0x0c;
		static constexpr int Enter = 0x0d;

		static constexpr int Shift = 0x10;
		static constexpr int Ctrl = 0x11;
		static constexpr int Alt = 0x12;
		static constexpr int Pause = 0x13;
		static constexpr int CapsLock = 0x14;
		static constexpr int IMEKanaMode = 0x15;
		static constexpr int IMEHanguelMode = 0x15;
		static constexpr int IMEOn = 0x16;
		static constexpr int IMEJunjaMode = 0x17;
		static constexpr int IMEFinalMode = 0x18;
		static constexpr int IMEHanjaMode = 0x19;
		static constexpr int IMEKanjiMode = 0x19;
		static constexpr int IMEOff = 0x1a;
		static constexpr int Esc = 0x1b;
		static constexpr int IMEConvert = 0x1c;
		static constexpr int IMENonconvert = 0x1d;
		static constexpr int IMEAccept = 0x1e;
		static constexpr int IMEModeChangeRequst = 0x1f;
		static constexpr int Space = 0x20;
		static constexpr int PageUp = 0x21;
		static constexpr int PageDown = 0x22;
		static constexpr int End = 0x23;
		static constexpr int Home = 0x24;
		static constexpr int LeftArrow = 0x25;
		static constexpr int UpArrow = 0x26;
		static constexpr int RightArrow = 0x27;
		static constexpr int DownArrow = 0x28;
		static constexpr int Select = 0x29;
		static constexpr int Print = 0x2a;
		static constexpr int Execute = 0x2b;
		static constexpr int PrintScreen = 0x2c;
		static constexpr int Insert = 0x2d;
		static constexpr int Delete = 0x2e;
		static constexpr int Help = 0x2f;
		static constexpr int Num0 = 0x30;
		static constexpr int Num1 = 0x31;
		static constexpr int Num2 = 0x32;
		static constexpr int Num3 = 0x33;
		static constexpr int Num4 = 0x34;
		static constexpr int Num5 = 0x35;
		static constexpr int Num6 = 0x36;
		static constexpr int Num7 = 0x37;
		static constexpr int Num8 = 0x38;
		static constexpr int Num9 = 0x39;

		static constexpr int A = 0x41;
		static constexpr int B = 0x42;
		static constexpr int C = 0x43;
		static constexpr int D = 0x44;
		static constexpr int E = 0x45;
		static constexpr int F = 0x46;
		static constexpr int G = 0x47;
		static constexpr int H = 0x48;
		static constexpr int I = 0x49;
		static constexpr int J = 0x4a;
		static constexpr int K = 0x4b;
		static constexpr int L = 0x4c;
		static constexpr int M = 0x4d;
		static constexpr int N = 0x4e;
		static constexpr int O = 0x4f;
		static constexpr int P = 0x50;
		static constexpr int Q = 0x51;
		static constexpr int R = 0x52;
		static constexpr int S = 0x53;
		static constexpr int T = 0x54;
		static constexpr int U = 0x55;
		static constexpr int V = 0x56;
		static constexpr int W = 0x57;
		static constexpr int X = 0x58;
		static constexpr int Y = 0x59;
		static constexpr int Z = 0x5a;
		static constexpr int LeftWindows = 0x5b;
		static constexpr int RightWindows = 0x5c;
		static constexpr int Applications = 0x5d;

		static constexpr int ComputerSleep = 0x5f;
		static constexpr int NumericKeypad0 = 0x60;
		static constexpr int NumericKeypad1 = 0x61;
		static constexpr int NumericKeypad2 = 0x62;
		static constexpr int NumericKeypad3 = 0x63;
		static constexpr int NumericKeypad4 = 0x64;
		static constexpr int NumericKeypad5 = 0x65;
		static constexpr int NumericKeypad6 = 0x66;
		static constexpr int NumericKeypad7 = 0x67;
		static constexpr int NumericKeypad8 = 0x68;
		static constexpr int NumericKeypad9 = 0x69;
		static constexpr int Multiply = 0x6a;
		static constexpr int Add = 0x6b;
		static constexpr int Separator = 0x6c;
		static constexpr int Subract = 0x6d;
		static constexpr int Decimal = 0x6e;
		static constexpr int Divide = 0x6f;
		static constexpr int F1 = 0x70;
		static constexpr int F2 = 0x71;
		static constexpr int F3 = 0x72;
		static constexpr int F4 = 0x73;
		static constexpr int F5 = 0x74;
		static constexpr int F6 = 0x75;
		static constexpr int F7 = 0x76;
		static constexpr int F8 = 0x77;
		static constexpr int F9 = 0x78;
		static constexpr int F10 = 0x79;
		static constexpr int F11 = 0x7a;
		static constexpr int F12 = 0x7b;
		static constexpr int F13 = 0x7c;
		static constexpr int F14 = 0x7d;
		static constexpr int F15 = 0x7e;
		static constexpr int F16 = 0x7f;
		static constexpr int F17 = 0x80;
		static constexpr int F18 = 0x81;
		static constexpr int F19 = 0x82;
		static constexpr int F20 = 0x83;
		static constexpr int F21 = 0x84;
		static constexpr int F22 = 0x85;
		static constexpr int F23 = 0x86;
		static constexpr int F24 = 0x87;
		static constexpr int F25 = 0x88;

		static constexpr int NumLock = 0x90;
		static constexpr int ScrollLock = 0x91;

		static constexpr int LetfShift = 0xa0;
		static constexpr int RightShift = 0xa1;
		static constexpr int LeftCtrl = 0xa2;
		static constexpr int RightCtrl = 0xa3;
		static constexpr int LeftAlt = 0xa4;
		static constexpr int RightAlt = 0xa5;
		static constexpr int BrowserBack = 0xa6;
		static constexpr int BrowserForward = 0xa7;
		static constexpr int BrowserRefresh = 0xa8;
		static constexpr int BrowserStop = 0xa9;
		static constexpr int BrowserSearch = 0xaa;
		static constexpr int BrowserFavorites = 0xab;
		static constexpr int BrowserStartAndHome = 0xac;
		static constexpr int VolumeMute = 0xad;
		static constexpr int VolumeDown = 0xae;
		static constexpr int VolumeUp = 0xaf;
		static constexpr int NextTrack = 0xb0;
		static constexpr int PreviousTrack = 0xb1;
		static constexpr int StopMedia = 0xb2;
		static constexpr int PlayOrPauseMedia = 0xb3;
		static constexpr int StartMail = 0xb4;
		static constexpr int SelectMedia = 0xb5;
		static constexpr int StartAppliction1 = 0xb6;
		static constexpr int StartAppliction2 = 0xb7;

		static constexpr int Semicolon = 0xba;
		static constexpr int OEM_1 = 0xba;
		static constexpr int PlusSign = 0xbb; 
		static constexpr int Comma = 0xbc;
		static constexpr int Minus = 0xbd;
		static constexpr int Period = 0xbe;
		static constexpr int Slash_QuestionMark = 0xbf;
		static constexpr int OEM_2 = 0xbf;
		static constexpr int GraveAccent_Tilde = 0xc0;
		static constexpr int OEM_3 = 0xc0;

		static constexpr int LeftBracket = 0xdb;
		static constexpr int OEM_4 = 0xdc;
		static constexpr int Backslash_VerticalBar = 0xdc;
		static constexpr int OEM_5 = 0xdb;
		static constexpr int RightBracket = 0xdd;
		static constexpr int OEM_6 = 0xdd;
		static constexpr int SingleQuote_DoubleQuote = 0xde;
		static constexpr int OEM_7 = 0xde;
		static constexpr int OEM_8 = 0xdf;

		static constexpr int OEM_102 = 0xe2;

		static constexpr int IMEProcess = 0xe5;

		static constexpr int Packet = 0xe7;

		static constexpr int Attn = 0xf6;
		static constexpr int CrSel = 0xf7;
		static constexpr int ExSel = 0xf8;
		static constexpr int EraseEOF = 0xf9;
		static constexpr int Play = 0xfa;
		static constexpr int Zoom = 0xfb;
		static constexpr int PA1 = 0xfd;
		static constexpr int OEM_Clear = 0xfe;
	};

	class Input
	{
	private:
		static std::bitset<0xff> _key_states_current;

		static std::bitset<0xff> _key_states_latest;

		static int _scroll_wheel;

		static int _mouse_position_x;

		static int _mouse_position_y;

		static EventCallBack<EventType::KeyDown> _event_key_down;

		static EventCallBack<EventType::KeyUp> _event_key_up;

		static EventCallBack<EventType::MouseMoved> _event_mouse_moved;

		static EventCallBack<EventType::MouseScrolled> _event_mouse_scrolled;

		static EventCallBack<EventType::FrameEnd> _event_frame_end;

	public:
		Input() = delete;

		static void Init();

		static bool GetKey(size_t keycode);

		static bool GetKeyDown(size_t keycode);

		static bool GetKeyUp(size_t keycode);

		static int GetScroolWheel();

		static int GetMousePositionX();

		static int GetMousePositionY();

		static void Reset();

	private:
		static void OnKeyDown(EventInfo<EventType::KeyDown>& event);

		static void OnKeyUp(EventInfo<EventType::KeyUp>& event);

		static void OnMouseScrolled(EventInfo<EventType::MouseScrolled>& event);

		static void OnMouseMoved(EventInfo<EventType::MouseMoved>& event);

		static void OnFrameEnd(EventInfo<EventType::FrameEnd>& event);

	};
}




#endif // !EXTRAX_INPUT_H
