# Introduction à la programmation Android

## Brève présentation de l'interface

### Le Manifest

C'est l'endroit où est stocké le fichier `AndroidManifest.xml`.
Ce fichier contient plusieurs informations clés d'une application comme les permissions,
les icônes et les différentes activités contenues dans l'application.
Ce fichier est au format XML.
Dans le cas d'une activité vide, il contient le code suivant :

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">

    <application
        android:allowBackup="true"
        android:dataExtractionRules="@xml/data_extraction_rules"
        android:fullBackupContent="@xml/backup_rules"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/Theme.Appel"
        tools:targetApi="31">
        <activity
            android:name=".MainActivity"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```
L'activité principale est donnée dans la balise `<activity>` qui contient le nom de l'activité : *MainActivity*.
On peut également trouver d'autres informations comme l'icône représentant l'application sur le téléphone, donnée par
`android:icon`, ou encore le nom de l'application donné par `android:label`.

### Les Ressources

Les ressources dans Android sont stockées dans le dossier `res` et contiennent plusieurs éléments importants pour l'application, notamment :

- **Drawable (`res/drawable/`)** : Contient les images et formes graphiques utilisées dans l'application.
- **Layout (`res/layout/`)** : Contient les fichiers XML qui définissent l'apparence des interfaces utilisateur.
- **Values (`res/values/`)** : Contient des fichiers XML pour stocker les chaînes de caractères (`strings.xml`), les couleurs (`colors.xml`), les dimensions (`dimens.xml`) et les styles (`styles.xml`).
- **Mipmap (`res/mipmap/`)** : Contient les icônes de l'application pour différentes résolutions d'écran.

Exemple d'un fichier `res/values/strings.xml` :

```xml
<resources>
    <string name="app_name">MonApplication</string>
    <string name="hello_world">Bonjour le monde !</string>
</resources>
```

### Le Code

Le code de l'application Android est principalement écrit en **Java** ou **Kotlin**.
La classe principale de l'application est généralement une activité qui hérite de `AppCompatActivity` et nommée MainActivity.

Exemple d'une activité de base en **java** :

```java
package com.example.appel;

import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
}
```

Dans cet exemple :
- La classe `MainActivity` hérite de `AppCompatActivity`.
- `onCreate` est une méthode appelée au lancement de l'application.
- `setContentView(R.layout.activity_main)` définit l'interface utilisateur en utilisant le fichier XML `activity_main.xml` situé dans `res/layout/`.

<h4>Exemple de Layout avec ConstraintLayout</h4>

Le fichier `res/layout/activity_main.xml` définit l'interface utilisateur de l'application.
Un des gestionnaires de mise en page les plus couramment utilisés est **ConstraintLayout**, qui permet d'organiser les éléments avec des contraintes flexibles.

Exemple de `activity_main.xml` utilisant `ConstraintLayout` :

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout 
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Bonjour le monde !"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
```

Dans cet exemple :
- Le `ConstraintLayout` est utilisé comme conteneur principal.
- Un `TextView` est ajouté au centre de l'écran grâce aux contraintes. Il affiche le texte "Bonjour le monde !".
Ce qui permet de centrer le texte dans l'écran est donné par les attributs `app:layout_constraintBottom_toBottomOf="parent"`, `app:layout_constraintLeft_toLeftOf="parent"`, `app:layout_constraintRight_toRightOf="parent"` et `app:layout_constraintTop_toTopOf="parent"`.

## Premières applications Android

Dans les sections qui suivent, nous allons explorer quelques concepts de base pour créer nos premières applications Android.

Dans cette première application, nous allons créer une activité qui permet d'obtenir un résultat sous forme de texte, en l'occurrence une date.

### Création d'une activité et retour d'un résultat

Notre première application consiste en la création de deux activités : `MainActivity` et `DateActivity`.
L'activité `MainActivity` déclenche l'affichage de l'activité `DateActivity` lorsqu'un bouton est cliqué.
Une fois que l'activité `DateActivity` est affichée, elle affiche un calendrier et retourne la date sélectionnée à l'activité `MainActivity`.

Nous avons donc deux activités :
1. **MainActivity** : L'activité principale qui déclenche l'affichage de la seconde activité.
2. **DateActivity** : L'activité qui retourne une date sous forme de texte.

#### L'activité `MainActivity`

L'activité principale `MainActivity` contient un bouton qui, lorsqu'il est cliqué, déclenche l'affichage de l'activité `DateActivity`.
Une fois que l'activité `DateActivity` retourne une date, elle est affichée dans un `TextView` de l'activité `MainActivity`.

```java
package com.example.calendrieractivite;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    Button   b;
    TextView tv;

    ActivityResultLauncher<Intent> launcher;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        launcher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                o -> {
                    if (o.getResultCode() == RESULT_OK) {
                        Intent data = o.getData();
                        if (data != null) {
                            tv.setText(data.getStringExtra("donnee"));
                        }
                    }
                });

        b  = findViewById(R.id.button);
        tv = findViewById(R.id.tv);

        b.setOnClickListener(v -> {
            Intent intent = new Intent(
                    v.getContext(),
                    Calendrier.class
            );
            launcher.launch(intent);
        });
    }
}
```

Plusieurs éléments sont à noter dans cette activité :
- `ActivityResultLauncher<Intent>` : C'est un objet qui permet de gérer le résultat retourné par une activité.
L'objet `Intent` est utilisé pour définir l'activité à lancer. C'est le type de données passé en entré à l'activité `DateActivity`.
- `registerForActivityResult` : Cette méthode permet de définir le comportement à adopter lorsqu'une activité retourne un résultat.
- `o -> { ... }` : C'est une expression lambda qui définit le comportement à adopter lorsqu'une activité retourne un résultat.
- `o.getResultCode() == RESULT_OK` : Cette ligne vérifie si le résultat retourné par l'activité est correct.
- `launcher.launch(intent)` : Cette ligne déclenche l'affichage de l'activité `DateActivity`.
- `tv.setText(data.getStringExtra("donnee"))` : Cette ligne affiche la date retournée par l'activité `DateActivity` dans un `TextView`.
D'une manière générale, le résultat retourné par une activité est stocké dans un objet `Intent` qui peut contenir plusieurs types de données.
Ces données peuvent être récupérées à l'aide de méthodes comme `getStringExtra`, `getIntExtra`, etc. faisant pensées à un tableau associatif.

#### `DateActivity.java`

```java
package com.example.calendrieractivite;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.ImageButton;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class Calendrier extends AppCompatActivity {

    CalendarView cv;
    ImageButton  b;
    String       date;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_calendrier);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        cv = findViewById(R.id.calendarView);
        b  = findViewById(R.id.retour);

        cv.setOnDateChangeListener((v, a, m, j) -> {
            date = a + "/" + (m + 1) + "/" + j;
        });

        b.setOnClickListener(v -> {
            Intent intent = getIntent();
            intent.putExtra("donnee", date);
            setResult(RESULT_OK, intent);
            finish();
        });
    }
}
```

Dans cette activité, nous avons :
- `cv.setOnDateChangeListener` : Cette méthode permet de définir un écouteur qui réagit lorsqu'une date est sélectionnée dans le calendrier.
- `intent.putExtra("donnee", date)` : Cette ligne stocke la date sélectionnée dans un objet `Intent` avec une clé "donnee".
- `setResult(RESULT_OK, intent)` : Cette ligne définit le résultat à retourner à l'activité `MainActivity`.
- `finish()` : Cette méthode termine l'activité `DateActivity` et retourne le résultat à l'activité appelante.
