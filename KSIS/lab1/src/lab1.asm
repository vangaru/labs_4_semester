.MODEL SMALL
.STACK 100h

.DATA
	surname	DB	'Ivanenko',13,10,'$'

.CODE

START:
	mov 	ax, @Data 			; пересылаем адрес сегмента данных в регистр AX
	mov 	ds, ax				; установка регистра dx на сегмент данных

	mov 	ah, 40h				; функция вывода строки
	mov 	bx, 1				; информация будет отображена на экране
	mov 	dx, OFFSET surname	; записать адрес строки в регистр DX
	mov 	cx, 5				; количество букв фамилии
	int 	21h					; вывод

	mov 	ah, 02h				; перейти на новую строку
	mov 	dl, 10				; вернуть каретку в начало строки
	int 	21h

	mov 	ah, 9h				; вывести строку
	mov 	cx, 4				; количество повторений цикла N-1

BEGIN:							;
	mov 	dx, OFFSET surname	; вывод фамилии
	int 	21h					;
	loop 	BEGIN				;

END START
