function get_notification(){$.ajax({type:"GET",async:true,url:"/notification/get",success:function(a){show_notification(a)}})}function show_notification(g){g=JSON.parse(g);var d="notification";var o=$.cookie(d);var b;var n=0;var m=new Array();var e=0;if(o!=null){b=o.split("|");for(var h=0;h<g.length;h++){var q=0;for(var f=0;f<b.length;f++){if(g[h].id==b[f]){q=1}}if(q==0){m[e]=h;e++}n=n+"|"+g[h].id}}else{for(var a=0;a<g.length;a++){m[e]=a;e++;n=n+"|"+g[a].id}}$.cookie(d,n,{expires:365,path:"/"});for(var c=0;c<m.length;c++){alert(g[m[c]].content)}}$().ready(function(){get_notification();setInterval(get_notification,60000)});