<html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
    <meta charset="UTF-8">
  <title>{title}</title>
  <link href="style.css" rel="stylesheet" type="text/css" media="all">
  <link href="custom.css" rel="stylesheet" type="text/css" media="all">
  <script type="text/javascript" src="spamlist.txt"></script>
  <script type="text/javascript" src="settings.txt"></script>
  <script type="text/javascript" src="spotwebserver.txt"></script>
  <script type="text/javascript" src="settings.txt"></script>
  <!-- <script type="text/javascript" src="blackkeys.xml.js"></script> -->
  <!-- <script type="text/javascript" src="whitekeys.xml.js"></script> -->
    <script type="text/javascript" src="bwlist.xml.txt"></script>
  <script>
    // Define spotter id
    var spotterLink = '{spotterlink}';
    var spotterName = spotterLink.match(/">(.+?)<\/a>/)[1];
	var spotterId = spotterLink.match(/.*title="(.+?)".*/)[1]; // Short ID
	var spotterId2 = spotterLink.match(/.*user:(.+?)#.*/)[1]; // Long ID
	var category = '{cat}', subCategory = '{subcat}';
	
    // Is the comment from the spotter
    // and is the commenter on the black- or whitelist?
    var commenterLink, commenterId, commenterId2, commenterName, commenterStatus, reacties_blacklist; // used in comment.tpl
    var counter1 = 0; // counter for comments
    var counter2 = 0; // counter for comments from spotter
    var counter1 = 0; // counter for comments
    var counter2 = 0; // counter for comments from spotter
    function checkComments(a,b) {
      if (b === "black") {
        document.write('<tr class="hidden">');
      } else if (a === 1) {
        document.write('<tr class="commentdivider">');
      } else if (a === 2 && b === "white") {
        document.write('<tr class="commentheader onwhitelist">');
      } else if (a === 2) {
        document.write('<tr class="commentheader">');
      } else if (a === 3 && spotterId === commenterId) {
        document.write('<tr class="comment commentspotter">');
        counter1++;
        counter2++;
      } else {
        document.write('<tr class="comment">');
        counter1++;
      }
    }
    
  </script>  
</head>

<body>
<div id="box">
  <div id="toolbar"><span class="toolbar-message"></span><span id="toolbar-top"></span></div>
  <div id="version"></div>
  <div id="content">
  <table>
    <tr>
      <td class="title">Omschrijving</td>
    </tr>
    <tr>
      <td id="description">{description}</td>
    </tr>
  </table>
  </div><!-- #content -->

  <div id="information">
  <table>
    <colgroup><col id="col1"><col id="col2"></colgroup>
    <tr><td colspan="2" class="title">Informatie</td></tr>
    <tr><td><b>Titel</b></td><td>{title}</td></tr>
    <tr><td><b>Weblink</b></td><td id="weblink">{website}</td></tr>
	<!-- <tr><td><b>Msgid</b></td><td>{msgid}</td></tr> -->
    <tr><td><b>Bestanden</b></td><td>{numfiles} bestanden&nbsp;&nbsp;|&nbsp;&nbsp;{size}</td></tr>
    <tr><td><b>Bestandsnaam</b></td><td><span class="file">{firstfile}</span> t/m <span class="file">{lastfile}</span></td></tr>
    <tr><td><b>Nieuwsgroepen</b></td><td><script>document.write('{newsgroup}'.replace(/ /g, "&nbsp; |&nbsp; "));</script></td></tr>
    <tr><td><b>Categorie&euml;n</b></td><td>{categories}</td></tr>
    <tr><td><b>Spotter</b></td><td>{spotterlink}&nbsp;&nbsp;|&nbsp;&nbsp;<script>document.write(spotterId);</script>&nbsp;&nbsp;|&nbsp;&nbsp;{tag} {taglink}</td></tr>
    <tr><td><b>Zoeken</b></td><td nowrap id="toolbar-info"></td></tr>
  </table>
  </div><!-- #information -->

  <div id="comments">
  <table class="commentstable">
    <tr>
      <td id="commentscounter" class="title"></td>
    </tr>
    {comments}
  </table>
  </div><!-- #comments -->
  
</div><!-- #box -->
  <script>


  function onWhiteList() {
    const box = document.getElementById("box");
    if (whiteList.indexOf(spotterId2) > -1) {
      box.className = "whitelist";
    } else if (blackList.indexOf(spotterId2) > -1) {
      box.className = "blacklist";
    } else {
      box.className = "";
    }
  }

  onWhiteList();
  
	    // Improve description
    var imdbLink, mmLink;
    function betterDescription() {
      var regexImdb = /https?:\/\/www\.imdb\.com\/title\/tt\d+\/?/i;
      var regexMm = /https?:\/\/www\.moviemeter\.nl\/film\/\d+/i;
      var description = document.getElementById("description").innerHTML;
      var webLink = document.getElementById("weblink").innerHTML;
      imdbLink = regexImdb.exec(webLink);
      mmLink = regexMm.exec(webLink);
      if (!imdbLink) {
        imdbLink = regexImdb.exec(description);
      }
      if (!mmLink) {
        mmLink = regexMm.exec(description);
      }
      description = description.replace(/(\b(https?|ftp|file):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/ig, '<a href="$1">$1</a>');
      description = description.replace(/\[img\]|\[\/img\]|\[color=(.+?)\]|\[\/color\]/ig, '');
      description = description.replace(/\[url=<a href="(.+?)">.+?<\/a>\](.+?)\[\/url\]/ig, '<a href="$1" title="$1">$2</a>');
      description = description.replace(/\[url="?spotnet:\/\/(\w+)@spot\.net"?\](.+?)\[\/url\]/ig, '<a href="' + nzbserver01 + '/#/?page=getspot&messageid=$1@spot.net" title="' + nzbserver01 + '/#/?page=getspot&messageid=$1@spot.net">$2 (spot)</a>');
      description = description.replace(/\[url\]|\[\/url\]/ig, '');
      description = description.replace(/<br>\?/ig, '<br>&bull; '); // bullet ipv ?
      description = description.replace(/(<br>\s*){5,}/ig, '<br><br><br><br>'); // max 4 breaks
      if (description === "") {
        description = 'Gegevens niet beschikbaar in spotlite!<br><br>Kijk op <a href="' + nzbserver03 + '/#/?page=getspot&messageid=' + encodeURIComponent('{msgid}') + '" class="nzbserver-url">NZBServer</a> voor de spotinformatie,<br><br>of download de spot met de nzb knopppen.'; // nzb server
      }
      document.getElementById("description").innerHTML = description;
    }
    betterDescription();

    // Clean title for urls to external sites
    function cleanTitle() {
      var strTitle = document.title;
      var year = strTitle.match(/(\b19\d{2}\b|\b20\d{2}\b)/);
      if (year) {
        year = " (" + year[0] + ")";
      } else {
        year = "";
      }
      if (category === "1" && subCategory !== "105") {
        strTitle = strTitle.replace(/\.|\_|\-|:/g, " ");
        strTitle = strTitle.replace(/\s\(.*\).*|\s\[.*\].*|\s\*.*\*.*/, ""); // remove ()[]** to end
        strTitle = strTitle.replace(/\(.*\)|\[.*\]|\*.*\*/, ""); // remove ()[]**
        strTitle = strTitle.replace(/(\s19\d{2}\b.*|\s20\d{2}\b.*)/, ""); // remove yyyy to end
        strTitle = strTitle.replace(/\ss\d{2}e\d{2}.*|\s\d{3,4}p\b.*|\sseizoen.*|\sseason.*|\ss\d{1,2}\b.*|\sse\s?\d.*|\safl\s+\d.*|\sbluray\b.*|\srental\b.*/i, ""); // remove to end
      } else if (category === "2") {
        strTitle = strTitle.replace(/\.|\_|\-|:/g, " ");
        strTitle = strTitle.replace(/\s\(.*\).*|\s\[.*\].*|\s\*.*\*.*/, ""); // remove ()[]** to end
        strTitle = strTitle.replace(/\(.*\)|\[.*\]|\*.*\*/, ""); // remove ()[]**
        strTitle = strTitle.replace(/(\b19\d{2}\b|\b20\d{2}\b)/g, ""); // remove yyyy global
        strTitle = strTitle.replace(/\d{2,3}khz|24bit|\bep\b|\bflac\b|\bgrindsman\b|\bhd\s?tracks\b|\bmp3\b|\bps3\b|\bsacd\b|\bwav\b/ig, ""); // remove global
      } else if (subCategory === "105") {
        strTitle = strTitle.replace(/\_|\-|:/g, " ");
        strTitle = strTitle.replace(/\((19\d{2}|20\d{2})\)/g, "$1"); // convert (yyyy) to yyyy global
        strTitle = strTitle.replace(/\(.*?\)|\[.*?\]|\*.*?\*/g, ""); // remove ()[]** global
        strTitle = strTitle.replace(/\bebook\b|\bepub\b|\bpdf\b/ig, ""); // remove global
        year = "";
      } else {
        strTitle = strTitle.replace(/\.(?=\D)|\_|\-|:/g, " ");
        strTitle = strTitle.replace(/\(.*?\)|\[.*?\]|\*.*?\*/g, ""); // remove ()[]** global
        year = "";
      }
      strTitle = strTitle.replace(/&amp;/g, '&');
      strTitle = strTitle.replace(/\bherpost\b|\brepost\b|\brespot\b|\bverzoek(je)?\b/ig, ""); // remove global
      strTitle = strTitle.replace(/\s+/g, " "); // remove whitespace
      strTitle = strTitle.trim();
      strTitle = strTitle.toLowerCase();
      if (strTitle.length > 2) {
        strTitle = strTitle + year;
      } else {
        strTitle = document.title;
      }
      strTitle = encodeURIComponent(strTitle);
      return strTitle;
    }
	// Generate NZB search buttons
    function NzbSearchButtons(query) {
      var buttonsHtml = "";
      for (var i = 0; i < searchSites.length; i++) {
        var site = searchSites[i];
        var link = site.url + encodeURIComponent(query);
        buttonsHtml += '<a class="search-button" href="' + link + '" target="_blank">' + site.name + '</a>';
      }
      return buttonsHtml;
    }

    // Create toolbars
    function createToolbars() {
      var strUrl = cleanTitle();
      var nzbSearch = "{firstfile}";
      var toolbarTop = document.getElementById("toolbar-top");
      var toolbarInfo = document.getElementById("toolbar-info");

      if (!nzbSearch) {
        return;
      }

      var pos = nzbSearch.lastIndexOf('.');
      if (pos != -1)  {
        nzbSearch = nzbSearch.substr(0, pos);
        if (nzbSearch.toLowerCase().indexOf(".part") != -1 || nzbSearch.toLowerCase().indexOf(".vol") != -1) {
          nzbSearch = nzbSearch.substr(0, nzbSearch.lastIndexOf('.'));
        }
      }
      // urls binsearch, nzbindex, and nzbking
     var webSites = NzbSearchButtons(nzbSearch);
      // urls  spotweb servers
      webSites += '<a href="' + nzbserver01 + '/?page=getnzb&action=display&messageid=' + encodeURIComponent('{msgid}') + '" class="spotweb-nzb" title="' + nzbserver01 + '/">NZB</a>';
      webSites += '<a href="' + nzbserver02 + '/?page=getnzb&action=display&messageid=' + encodeURIComponent('{msgid}') + '" class="spotweb-nzb" title="' + nzbserver02 + '/">NZB</a>';
      // urls google, youtube, imdb and moviemeter
      webSites += ('<a href="https://www.google.nl/search?q=' + strUrl + '" class="media-url">Google</a>');
      if ((category === "1" &&  subCategory !== "105") || category === "2") {
      webSites += ('<a href="https://www.youtube.com/results?search_query=' + strUrl + '" class="media-url">YouTube</a>');
      }
      if (!imdbLink) {
        imdbLink = ('http://www.imdb.com/find?s=tt&q=' + strUrl);
      }
      if (category === "1" &&  subCategory !== "105") {
        webSites += ('<a href="' + imdbLink + '" class="media-url">IMDb</a>');
      }
      if (!mmLink) {
        mmLink = ('https://www.google.nl/search?q=' + strUrl + ' moviemeter');
      }
      if (category === "1" &&  subCategory !== "105" && '{categories}'.indexOf("TV Series") === -1) {
        webSites += ('<a href="' + mmLink + '" class="media-url" title="MovieMeter">MM</a>');
      }
	  webSites += '<a href="#" class="check-version" onclick="CopySpotLink()" title="Spotlink kopi&#235;ren">Spotlink</a>';
	  webSites += '<a href="#" class="check-version" onclick="checkForUpdates()" title="Controleer of er updates zijn.">Updates</a>';
      
      toolbarTop.innerHTML = webSites;
      toolbarInfo.innerHTML = webSites;
    }
    createToolbars();


    // Configuration spotimage
    var afbeelding_positie, afbeelding_toggle, preview_breedte, previewSize;
    var spotImage = document.querySelector('#description > img:first-child');
    if (spotImage) { spotImageConfig(); }
    function spotImageConfig() {
      spotImage.removeAttribute("onload");
      spotImage.removeAttribute("onmouseover");
      spotImage.removeAttribute("onmouseout");

      if (afbeelding_positie === 1) {
        spotImage.style.float = "right";
        spotImage.style.marginLeft = "15px";
        spotImage.style.marginRight = "0px";
      } else {
        spotImage.style.marginRight = "15px";
      }

      if (preview_breedte > 0) {
        spotImage.style.maxWidth = preview_breedte + "px";
        previewSize = preview_breedte + "px"
      } else {
        spotImage.style.maxWidth = "225px";
        previewSize = "225px";
      }

      if (afbeelding_toggle === 1) {
        spotImage.addEventListener("click", spotImageSize);
      } else {
        spotImage.addEventListener("mouseover", function(){ spotImage.style.maxWidth = "100%"; });
        spotImage.addEventListener("mouseout", function(){ spotImage.style.maxWidth = previewSize; });
      }
    }   

    function spotImageSize() {
      if (spotImage.style.maxWidth === "100%") {
        spotImage.style.maxWidth = previewSize;
      } else {
        spotImage.style.maxWidth = "100%";
      }
    }
    

    // Shows the total number of comments
    function totalComments() {
      var commentsCounter = document.getElementById("commentscounter");
      if (counter1 === 0) {
        commentsCounter.innerHTML = "Geen reacties";
      } else if (counter1 === 1) {
        commentsCounter.innerHTML = "1 reactie";
      } else {
        commentsCounter.innerHTML = counter1 + " reacties";
      }
      if (counter2 > 0) {
        commentsCounter.innerHTML += "<span>( " + counter2 + " van " + spotterName + " )</span>";
      }
    }
    totalComments();
    

    // Improve comments
    var filter, scheldwoorden;
    function betterComments() {
      if (scheldwoorden === 0) {
        filter = spam;
      } else if (category === "9") {
        filter = spam.concat(badwords,["(<br>[^a-z0-9]*\n){4,}","(<br>.{0,2}\\n){4,}","a\\W*f\\W*s\\W*c\\W*h\\W*i\\W*e\\W*t\\W*e\\W*n","\\ba+p(en)?\\b","f\\W*l\\W*i\\W*k\\W*k\\W*e\\W*r\\W*s?\\b","h\\W*o\\W*m\\W*o","n\\W*e\\W*g\\W*e\\W*r\\W*s?\\b","n\\W*i\\W*c\\W*h\\W*t","\\bn\\W*i\\W*k\\W*k\\W*e\\W*r\\W*s?\\b","s\\W*m\\W*e\\W*r\\W*i\\W*g\\W*e","s\\W*t\\W*e\\W*r\\W*f\\b","s\\W*t\\W*r\\W*o\\W*n\\W*(d|t)","v\\W*e\\W*r\\W*g\\W*a\\W*s\\W*s\\W*e\\W*n","v\\W*u\\W*i\\W*l\\W*e","\\bz\\W*w\\W*a\\W*r\\W*t\\W*e\\W*n\\b"]);
      } else {
        filter = spam.concat(badwords);
      }
      var regexFilter = new RegExp(filter.join('|'),"i");
      var signatures = /<br>[\s\S]?<br>-{2,3}\s{1,2}<br>[\s\S]*http[\s\S]*/; // Avast en Spotnet 2.0
      var comments = document.querySelectorAll(".comment td");
      if (comments) {
        var lengthComments = comments.length;
        for (var i = 0; i < lengthComments; i++) {
          comments[i].innerHTML = comments[i].innerHTML.replace(signatures,"");
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[img=(.+?)\]/ig, '<img src="qrc:/smileys/klappen.gif">'); // for unknown smileys
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[quote="*(.+?)"*\]/ig, '<blockquote><div><cite>$1 schreef:</cite></div>');
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[\/quote\]/ig, '</blockquote>');
          comments[i].innerHTML = comments[i].innerHTML.replace(/(\b(https?|ftp|file):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/ig, '<a href="$1">$1</a>');
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[url=<a href="(.+?)">.+?<\/a>\](.+?)\[\/url\]/ig, '<a href="$1" title="$1">$2</a>');
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[url="?spotnet:\/\/(\w+)@spot\.net"?\](.+?)\[\/url\]/ig, '<a href="' + nzbserver01 + '/#/?page=getspot&messageid=$1@spot.net" title="' + nzbserver01 + '/#/?page=getspot&messageid=$1@spot.net">$2 (spot)</a>');
          comments[i].innerHTML = comments[i].innerHTML.replace(/\[url\]|\[\/url\]|\[color=(.+?)\]|\[\/color\]/ig, '');
          if (regexFilter.test(comments[i].innerHTML)) {
          comments[i].innerHTML = '<img class="censored-on" onclick="toggleCensored(this)" src="qrc:/smileys/censored.gif"><div><br>' + comments[i].innerHTML + '</div>';
          }
        }
      }
    }
    betterComments();


    // Click on censored image to toggle comment visibility
    function toggleCensored(afb) {
      if (afb.className === "censored-on") {
        afb.className = "censored-off";
      } else {
        afb.className = "censored-on";
      }
    }

    // Compare versions
    function compareVersions(v1, v2) {
      var a = v1.split('.').map(Number);
      var b = v2.split('.').map(Number);
      var len = Math.max(a.length, b.length);
      for (var i = 0; i < len; i++) {
        var partA = a[i] || 0;
        var partB = b[i] || 0;
        if (partA > partB) return 1;
        if (partA < partB) return -1;
      }
      return 0;
    }

    // Update checker
    function checkForUpdates() {
      var version = document.getElementById("version");
      var counter = 0;

      var script = document.createElement("script");
      script.type = "text/javascript"; 
      script.src = atob("aHR0cDovL3JhZGlvbmwuNDJ3ZWIuaW8vdmVyc2llLnR4dA==");
      script.onerror = function () {
        console.error("Fout bij het laden van versie.txt.");
        version.innerHTML = "<p><b>Fout bij het laden van versie-informatie. Probeer het later.</b></p>";
      };
      document.getElementsByTagName("head")[0].appendChild(script);

      version.className = "version-on";
      version.innerHTML = "<p><b>Een ogenblik geduld...</b></p>";

      var myInterval = setInterval(checkVersion, 200);

      function checkVersion() {
        counter++;
        if (counter > 40) {
          clearInterval(myInterval);
          version.innerHTML = "<img src='img/close.png' onclick='closeUpdateScreen(version)' style='position:absolute; top:5px; right:5px; border:5px solid transparent; cursor:pointer;'><p>Geen informatie kunnen vinden.<br>Probeer het later nog eens.<br></p>";
        } else if (typeof newVersion !== 'undefined') {
          clearInterval(myInterval);

          if (typeof updateMessage === 'undefined') {
            updateMessage = "Er is een update beschikbaar";
          }

          var comparison = compareVersions(newVersion, currentVersion);
          if (comparison === 0) {
            updateMessage = "U gebruikt de nieuwste versie";
          } else if (comparison < 0) {
            updateMessage = "U gebruikt een nieuwere versie dan beschikbaar is (testversie?)";
          }
		   version.innerHTML = "<img src=\"img/close.png\" onclick=\"closeUpdateScreen(version)\" style=\"position:absolute; top:5px; right:5px; border:5px solid transparent; cursor:pointer;\"><p><b>" + updateMessage + "</b><br><br>Huidige versie: " + currentVersion + "<br>Nieuwste versie: " + newVersion + "<br><br><a href=\"" + newVersionLink + "\">Download skin Sunny Ext. v" + newVersion + "</a><br><br>Volgende update: " + nextRelease + "<br><br>Informatie en support<br><a href=\"http://goo.gl/qLH27V\">Download documentatie</a><br><br>Tip:<br>NZB-bestanden downloaden via clubnzb.com <i>(wachtwoord per NZB ondersteuning)</i>, zie NZB knop in deze skin.<br><br>Open je NZB-bestand direct in <a href=\"https://sabnzbd.org\">SABnzbd</a> - downloaden, repareren en uitpakken gebeurt helemaal automatisch.<br></p>";
        }
      }
    }
	 // Copy Spot link (msgid / title)
    function CopySpotLink() {
        var spottitle = document.getElementsByTagName("title")[0].innerHTML;
		var text = spottitle.replace(/"/g, "&quot;").replace(/'/g, "&#039;");
        var version = document.getElementById("version");
        var textbox = document.createElement("textbox");
        document.getElementsByTagName("head")[0].appendChild(textbox);
        version.className = "spotlink";
        version.innerHTML = "<img src=\"img/close.png\" onclick=\"closeUpdateScreen(version)\" style=\"position:absolute; top:5px; right:5px; border:5px solid transparent; cursor:pointer;\"><p><b>Spotlink kopi&#235;ren</b></p><p>Kopieer en plak onderstaande <u>spotlink</u> in een bericht.<br><br><b>[url=spotnet://{msgid}]" + text + "[/url]</b></p>"; 
    }
	

    // Close the update screen
    function closeUpdateScreen(screen) {
      screen.innerHTML = "";
      screen.className = "";
    }

  </script>
</body>
</html>
