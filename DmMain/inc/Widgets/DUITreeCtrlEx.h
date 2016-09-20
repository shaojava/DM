//-------------------------------------------------------
// Copyright (c) DuiMagic
// All rights reserved.
// 
// File Name: DUITreeCtrlEx.h 
// File Des: 
// File Summary: 
// Cur Version: 1.0
// Author:
// Create Data:
// History:
// 		<Author>	<Time>		<Version>	  <Des>
//      guoyou		2015-2-26	1.0			
//-------------------------------------------------------
#pragma once
#include "DUIScrollBase.h"
#include "DUIItemPanel.h"
#include "DMTreeT.h"

namespace DMAttr
{
	/// <summary>
	///		<see cref="DM::DUITreeCtrlEx"/>��xml���Զ���
	/// </summary>
	class DUITreeCtrlExAttr:public DUIScrollBaseAttr
	{
	public:
		static wchar_t* SKIN_toggleskin;								    ///< չ��������С����ͼ��,����״̬(��������+չ������),ʾ��:toggleskin="treetoggle"
		static wchar_t* SKIN_checkskin;                                     ///< ѡ�С���ѡ�У���ѡ��ͼ��,����������checkbox״̬��9��״̬(��������+ѡ������+��ѡ������),ʾ��:checkskin="treecheck"
		static wchar_t* SKIN_itembgskin;                                    ///< �����ڵı���ͼ��,����/ͣ��/ѡ��,ʾ��:itembgskin="itembgskin"
		static wchar_t* COLOR_clritembg;                                    ///< item��ı���ɫ,ʾ��:clritembg="pbgra(ff,ff,ff,ff)"
		static wchar_t* COLOR_clritemhoverbg;                               ///< item���ͣ������ɫ,ʾ��:clritemhoverbg="pbgra(ff,ff,ff,ff)"
		static wchar_t* COLOR_clritemselbg;                                 ///< item���ѡ�б���ɫ,ʾ��:clritemselbg="pbgra(ff,ff,ff,ff)"
		static wchar_t* INT_childoffset;                                    ///< ��������ڸ����ƫ��,�ɱ��������,ʾ��:childoffset="20"
		static wchar_t* INT_itemheight;									    ///< ÿ��߶�,�ɱ��������,ʾ��:itemheight="20"
		static wchar_t* INT_itemwidth;									    ///< ÿ�����,�ɱ��������,ʾ��:itemwidth="20"
		static wchar_t* bool_brightclicksel;                                ///< �Ƿ�֧���һ�ѡ��,ʾ��:brightclicksel="1"
		static wchar_t* bool_bcheckbox;                                     ///< �Ƿ�����checkbox,ʾ��:bcheckbox="1"

		static wchar_t* NODE_treeitem;										///< treectrl��xml������
		static wchar_t* ITEM_bcollapsed;									///< ���Ƿ�����,ʾ��:bcollapsed="1"
		static wchar_t* ITEM_height;                                        ///< ��ĸ߶�(��ѡ),ʾ��:height="10"
		static wchar_t* ITEM_width;                                         ///< ��Ŀ���(��ѡ),ʾ��:weidth="10"
		static wchar_t* ITEM_childoffset;                                   ///< ��Ŀ���(��ѡ),ʾ��:childoffset="10"
		static wchar_t* ITEM_data;											///< �������,ʾ��:data="1"
	};
	DMAttrValueInit(DUITreeCtrlExAttr,SKIN_toggleskin)DMAttrValueInit(DUITreeCtrlExAttr,SKIN_checkskin)DMAttrValueInit(DUITreeCtrlExAttr,SKIN_itembgskin)DMAttrValueInit(DUITreeCtrlExAttr,COLOR_clritembg)DMAttrValueInit(DUITreeCtrlExAttr,COLOR_clritemhoverbg)
	DMAttrValueInit(DUITreeCtrlExAttr,COLOR_clritemselbg)DMAttrValueInit(DUITreeCtrlExAttr,INT_childoffset)DMAttrValueInit(DUITreeCtrlExAttr,INT_itemheight)DMAttrValueInit(DUITreeCtrlExAttr,INT_itemwidth)
	DMAttrValueInit(DUITreeCtrlExAttr,bool_brightclicksel)DMAttrValueInit(DUITreeCtrlExAttr,bool_bcheckbox)DMAttrValueInit(DUITreeCtrlExAttr,NODE_treeitem)DMAttrValueInit(DUITreeCtrlExAttr,ITEM_bcollapsed)
	DMAttrValueInit(DUITreeCtrlExAttr,ITEM_height)DMAttrValueInit(DUITreeCtrlExAttr,ITEM_width)DMAttrValueInit(DUITreeCtrlExAttr,ITEM_childoffset)DMAttrValueInit(DUITreeCtrlExAttr,ITEM_data)
}

namespace DM
{
	enum 
	{
		DMTVEX_COLLAPSE = 1,///< ����
		DMTVEX_EXPAND,	   ///< չ��
		DMTVEX_TOGGLE,	   ///< �Զ���ԭ����չ��������
	};

	enum ///< ��������
	{
		DMTVEXMask_Toggle         = 0x00000001UL, 
		DMTVEXMask_CheckBox       = 0x00000002UL, 
	};

	enum ///< ����Ƿ�ͣ����С���ǵľ�������
	{
		DMTVEXBtn_None,					               
		DMTVEXBtn_Toggle, 
		DMTVEXBtn_CheckBox,
	};

	enum 
	{
		DMTVEXCheckBox_UnChecked,			///< δѡ��
		DMTVEXCheckBox_Checked,				///< ѡ��
		DMTVEXCheckBox_PartChecked			///< ����ѡ��
	};

	/// <summary>
	///		
	/// </summary>
	typedef struct stTVITMEX
	{
		stTVITMEX(DMXmlNode XmlNode, IDMItemPanelOwner* pItemOwner)
		{
			pPanel.Attach(new DUIItemPanel(XmlNode,pItemOwner));
			hItem = iHeight = iChildOffset = nLevel = lParam = NULL;
			bVisible = true;
			iWidth = 20; 
			iCheckValue = DMTVEXCheckBox_UnChecked;
			bCollapsed = true;
			bHasChildren = false;
			dwToggleState = DUIWNDSTATE_Normal;
			dwCheckBoxState	= DUIWNDSTATE_Normal;
		}
		virtual~stTVITMEX()
		{
			pPanel.Release();
		}
		DMSmartPtrT<DUIItemPanel>       pPanel;			 ///< ���
		HDMTREEITEM						hItem;			 ///< �����еı�ʶ  
		int								nLevel;			 ///< �����Ĳ��	
		int								iHeight;		 ///< �߶�
		int								iWidth;			 ///< ����
		int                             iChildOffset;    ///< ��������ڸ����ƫ��,����toggleskinʱ,�ڼ���ʱ���Զ�����toggleskin��checkskin�Ŀ��ȣ�����Ҳ�ᱻȫ�ֵ�ichildoffsetӰ�쵽,��������һ�����Լ����ichildoffset=0��
		int								iCheckValue;	 ///< checkbox��ǰ״̬������,ѡ��,��ѡ�У�
		DWORD							dwCheckBoxState; ///< checkbox״̬(normal,hover,sel)
		DWORD							dwToggleState;	 ///< �۵�С���ǵ�״̬(normal,hover,sel)
		bool							bCollapsed;      ///< �۵�״̬
		bool							bVisible;		 ///< �Ƿ�ɼ�
		bool							bHasChildren;    ///< �Ƿ��������
		LPARAM							lParam;			 ///< data
	}TVITEMEX,*LPTVITEMEX;


	/// <summary>
	///		 DUITreeCtrlEx������ʵ�֣����ԣ�<see cref="DMAttr::DUITreeCtrlExAttr"/>
	/// </summary>
	class DM_EXPORT DUITreeCtrlEx 
		: public DUIScrollBase
		, public IDMItemPanelOwner
		, public DMTreeT<LPTVITEMEX>
	{
		DMDECLARE_CLASS_NAME(DUITreeCtrlEx, DUINAME_TreeCtrlEx,DMREG_Window)
	public:
		DUITreeCtrlEx();
		~DUITreeCtrlEx();
		
	public:
		//---------------------------------------------------
		// Function Des: ����ӿ�
		//---------------------------------------------------
		bool RemoveAllItems();																			///< �Ƴ����н��
		bool RemoveItem(HDMTREEITEM hItem);
		bool SetItemRect(HDMTREEITEM hItem, CRect rcItem);												///< ����ĳ�������
		
		///---------------------------------
		/// ���뺯��
		HDMTREEITEM InsertItem(LPTVITEMEX pData,HDMTREEITEM hParent,HDMTREEITEM hInsertAfter,BOOL bEnsureVisible);
		HDMTREEITEM InsertItem(DMXmlNode &XmlItem,HDMTREEITEM hParent=DMTVI_ROOT, HDMTREEITEM hInsertAfter=DMTVI_LAST,BOOL bEnsureVisible=FALSE);

		///---------------------------------
		/// ��ȡϵ�к������ɲο�CTreeCtrl�ĳ�Ա�����б�
		HDMTREEITEM GetRootItem();
		HDMTREEITEM GetRootItem(HDMTREEITEM hItem);
		HDMTREEITEM GetNextSiblingItem(HDMTREEITEM hItem);
		HDMTREEITEM GetPrevSiblingItem(HDMTREEITEM hItem);
		HDMTREEITEM GetChildItem(HDMTREEITEM hItem,bool bFirst =true);
		HDMTREEITEM GetParentItem(HDMTREEITEM hItem);
		HDMTREEITEM GetSelectedItem();
		HDMTREEITEM GetNextItem(HDMTREEITEM hItem);
		bool SelectItem(HDMTREEITEM hItem,bool bEnsureVisible=true);
		bool HoverItem(HDMTREEITEM hItem,bool bEnsureVisible=true);
		bool ItemHasChildren(HDMTREEITEM hItem);
		bool SetItemData(HDMTREEITEM hItem, LPARAM lParam);
		LPARAM GetItemData(HDMTREEITEM hItem) const;

		bool GetCheckState(HDMTREEITEM hItem) const;    
		bool SetCheckState(HDMTREEITEM hItem,bool bCheck);   

		bool Expand(HDMTREEITEM hItem,UINT nCode = DMTVEX_EXPAND);
		bool EnsureVisible(HDMTREEITEM hItem,bool bFirstVisible = false);

	public:// ���ƣ�������
		virtual void DrawItem(IDMCanvas* pCanvas,CRect& rc,HDMTREEITEM hItem);
		virtual void RedrawItem(HDMTREEITEM hItem);

	public:
		DM_BEGIN_MSG_MAP()
			DM_MSG_WM_PAINT(DM_OnPaint)
			MSG_WM_DESTROY(OnDestroy)
			MSG_WM_LBUTTONDOWN(OnLButtonDown)
			MSG_WM_LBUTTONDBLCLK(OnLButtonDbClick)
			MSG_WM_LBUTTONUP(OnLButtonUp)
			MSG_WM_RBUTTONDOWN(OnRButtonDown);
			MSG_WM_MOUSEMOVE(OnMouseMove)
			MSG_WM_MOUSELEAVE(OnMouseLeave)
			DM_MSG_WM_SETFOCUS(DM_OnSetFocus)
			DM_MSG_WM_KILLFOCUS(DM_OnKillFocus)
			MSG_WM_CHAR(OnChar)
			MSG_WM_KEYDOWN(OnKeyDown)
			MSG_WM_MOUSEWHEEL(OnMouseWheel)
			MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST,WM_MOUSELAST,OnMouseEvent)
			MESSAGE_RANGE_HANDLER_EX(WM_KEYFIRST,WM_KEYLAST,OnKeyEvent)
			MESSAGE_RANGE_HANDLER_EX(WM_IME_STARTCOMPOSITION,WM_IME_KEYLAST,OnKeyEvent)
			MESSAGE_HANDLER_EX(WM_IME_CHAR,OnKeyEvent)
		DM_END_MSG_MAP()
	public:
		//---------------------------------------------------
		// Function Des: DUI����Ϣ�ַ�ϵ�к���
		//---------------------------------------------------
		void DM_OnPaint(IDMCanvas* pCanvas);
		void OnDestroy();
		void OnLButtonDown(UINT nFlags,CPoint pt);
		void OnLButtonDbClick(UINT nFlags,CPoint pt);
		void OnLButtonUp(UINT nFlags,CPoint pt);
		void OnRButtonDown(UINT nFlags, CPoint pt);
		void OnMouseMove(UINT nFlags,CPoint pt);
		void OnMouseLeave();
		void DM_OnSetFocus();
		void DM_OnKillFocus();
		void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
		void OnKeyDown(TCHAR nChar, UINT nRepCnt, UINT nFlags);
		BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
		LRESULT OnMouseEvent(UINT uMsg,WPARAM wParam,LPARAM lParam);
		LRESULT OnKeyEvent(UINT uMsg,WPARAM wParam,LPARAM lParam);

	public:
		//---------------------------------------------------
		// Function Des: �����غ���
		//---------------------------------------------------
		virtual DMCode DV_CreateChildWnds(DMXmlNode &XmlNode);
		virtual DMCode DV_OnSetCursor(const CPoint &pt);
		virtual DMCode DV_OnUpdateToolTip(CPoint pt, DMToolTipInfo &tipInfo);
		virtual void LoadBranch(HDMTREEITEM hParent,DMXmlNode &XmlItem);
		virtual void LoadItemAttribute(DMXmlNode &XmlItem, LPTVITEMEX pData);      	
		virtual void OnNodeFree(LPTVITEMEX &pItemData);
		virtual int GetScrollLineSize(bool bVert){return m_iDefItemHei;};
		

		// ����ʵ��
		DUIWindow* GetOwnerWindow();   
		DMCode OnSetCapture(DUIItemPanel* pPanel);
		DMCode OnReleaseCapture(DUIItemPanel* pPanel);
		DMCode OnGetPanelRect(DUIItemPanel* pPanel,LPRECT lpRect);							///< ��ʹ��*lpRect��ֵ��

	public:// ����
		void SetChildrenVisible(HDMTREEITEM hItem,bool bVisible);
		void SetChildrenState(HDMTREEITEM hItem,int iCheckValue);
		void CheckState(HDMTREEITEM hItem, bool bCheck,bool bCheckChild = true);  
		bool CheckChildrenState(HDMTREEITEM hItem,bool bCheck);			// �����ڵ����к�bCheck��һ����״̬,�򷵻�false��ȫһ�·���true
		bool IsAncestor(HDMTREEITEM hItem1,HDMTREEITEM hItem2);         // hItem2�Ƿ�ΪhItem1������
		bool ItemIsValid(HDMTREEITEM hItem);

		void ModifyToggleState(HDMTREEITEM hItem, DWORD dwStateAdd, DWORD dwStateRemove);
		void ModifyChekcBoxState(HDMTREEITEM hItem, DWORD dwStateAdd, DWORD dwStateRemove);
		void ItemLButtonDown(HDMTREEITEM hItem, UINT nFlags,CPoint pt);
		void ItemLButtonUp(HDMTREEITEM hItem, UINT nFlags,CPoint pt);
		void ItemLButtonDbClick(HDMTREEITEM hItem, UINT nFlags,CPoint pt);
		void ItemMouseMove(HDMTREEITEM hItem, UINT nFlags,CPoint pt);
		void ItemMouseLeave(HDMTREEITEM hItem);

		
		// λ�����
		HDMTREEITEM HitTest(CPoint &pt);													///< �Զ��޸�pt��λ��Ϊ��Ե�ǰ���ƫ����(�紦��XOffset��һ������,��pt.xΪ��ֵ)
		int ItemHitTest(HDMTREEITEM hItem,CPoint &pt) const;								///<����pt�ѱ�ת����Ϊ��Ե�ǰ���ƫ������ֻ���ж�x����

		int GetTotalHeight();
		int GetTotalWidth();
		int GetItemHeightWithAllChild(HDMTREEITEM hItem);									///< ����ĳһ���Լ��������пɼ�������ܸ߶�
		int GetItemWidthWithAllChild(HDMTREEITEM hItem);									///< ����ĳһ���Լ��������пɼ�������ܿ���
		int GetItemXOffset(HDMTREEITEM hItem);                                              ///< ����ĳ�������ƫ�ƣ����ɼ�����Ϊ0��
		int GetItemYOffset(HDMTREEITEM hItem);                                              ///< ����ĳ�������ƫ�ƣ����ɼ�����Ϊ0��
		bool GetItemRect(HDMTREEITEM hItem,CRect &rcItem);									///< ����ĳ������(��rcClient��ͬһ����ϵ��
		bool GetToggleRect(HDMTREEITEM hItem,CRect &rcToggle);                              ///< ����ĳ��toggle����(��rcClient��ͬһ����ϵ��
		bool GetCheckBoxRect(HDMTREEITEM hItem,CRect &rcCheckBox);                          ///< ����ĳ��checkbox����(��rcClient��ͬһ����ϵ��
		void UpdateScrollRangeSize();

	public:
		DM_BEGIN_ATTRIBUTES()  
			DM_SKINPTR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::SKIN_toggleskin, m_pToggleSkin, DM_ECODE_NOXMLLOADREFRESH)  
			DM_SKINPTR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::SKIN_checkskin, m_pCheckSkin, DM_ECODE_NOXMLLOADREFRESH)  
			DM_SKINPTR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::SKIN_itembgskin, m_pItemBgSkin, DM_ECODE_NOXMLLOADREFRESH)  

			DM_INT_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::INT_childoffset, m_iDefChildOffset, DM_ECODE_NOXMLLOADREFRESH)
			DM_INT_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::INT_itemheight,  m_iDefItemHei,     DM_ECODE_NOXMLLOADREFRESH)
			DM_INT_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::INT_itemwidth,  m_iDefItemWid,     DM_ECODE_NOXMLLOADREFRESH)
			DM_bool_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::bool_brightclicksel, m_bRightClickSel, DM_ECODE_NOXMLLOADREFRESH)
			DM_bool_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::bool_bcheckbox, m_bCheckBox, DM_ECODE_NOXMLLOADREFRESH)
			DM_COLOR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::COLOR_clritembg,		m_crItemBg[0],DM_ECODE_NOXMLLOADREFRESH)
			DM_COLOR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::COLOR_clritemhoverbg,m_crItemBg[1],DM_ECODE_NOXMLLOADREFRESH)
			DM_COLOR_ATTRIBUTE(DMAttr::DUITreeCtrlExAttr::COLOR_clritemselbg,	m_crItemBg[2],DM_ECODE_NOXMLLOADREFRESH)
		DM_END_ATTRIBUTES()

	public:
		IDMSkinPtr					m_pToggleSkin;			///< С����6��ͼ
		IDMSkinPtr					m_pCheckSkin;			///< checkbox9��ͼ
		IDMSkinPtr					m_pItemBgSkin;			///< ��������ͼ
		DMColor					    m_crItemBg[3];			///< ��������ɫ

		int						    m_iDefItemHei;		    ///< ���Ĭ�ϸ߶�
		int						    m_iDefItemWid;		    ///< ���Ĭ�Ͽ���
		int							m_iDefChildOffset;      ///< ������Ը���Ĭ��ƫ��

		bool						m_bRightClickSel;       ///< �Ƿ�֧���һ�ѡ��
		bool						m_bCheckBox;			///< �Ƿ�����checkbox

		// ����
		HDMTREEITEM					m_hSelItem;				///< ��ǰѡ����
		HDMTREEITEM					m_hHoverItem;           ///< ��ǰͣ����
		HDMTREEITEM					m_hCaptureItem;         ///< ���capture��(������������ٻظ�)

		// 
		int							m_nItemHoverBtn;		///< ��ӦС���Ǻ�checkbox
		int							m_nItemPushDownBtn;

		//
		DMSmartPtrT<DUIItemPanel>	m_pCapturePanel;		///< ��ǰ������setcapture�����,�����ֻ����갴�µ�˲�����ã��������
	};

}//namespace DM