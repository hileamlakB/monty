>       ; move to p1
,       ; read character and store it in p1
>       ; move pointer to p2 (second byte)
,       ; read character and store it in p2


@2
[           ; enter loop
<   @1
	[
	   <+          @0
	   >>>+        @3
	   <<-      @1
	]

-
]
